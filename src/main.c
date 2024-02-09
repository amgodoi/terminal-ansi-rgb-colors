/**
 * main.c
 */
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <wchar.h>
#include <locale.h>

#define COLOR_RGB L"\033[38;2;%u;%u;%um"
#define COLOR_RESET_TO_DEFAULT L"\033[0m"

void change_terminal_color(uint8_t r, uint8_t g, uint8_t b);
void reset_terminal_to_default_color();

/* OBS: works only in true colors terminals as KITTY */
int main()
{
    (void) setlocale(LC_CTYPE, "");

    wchar_t *s = L"Hello, world!!!";

    for (uint16_t r = 0; r < 256; r++) {
        for (uint16_t g = 0; g < 256; g++) {
            for (uint16_t b = 0; b < 256; b++) {
                change_terminal_color(r, g, b);
                wprintf(L"%3u, %3u, %3u - %ls\n", r, g, b, s);
            }
        }
    }

    reset_terminal_to_default_color();

    return 0;
}

void change_terminal_color(uint8_t r, uint8_t g, uint8_t b)
{
    wprintf(COLOR_RGB, r, g, b);
}

void reset_terminal_to_default_color()
{
    wprintf(L"%ls", COLOR_RESET_TO_DEFAULT);
}
