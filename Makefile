# Makefile to small project
TARGET ?= main
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name "*.c")
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CC = gcc
USER_FLAGS = 
CFLAGS ?= $(INC_FLAGS) $(USER_FLAGS) -MMD -MP -Wall -Wextra -Wpedantic -Werror

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBES) $(LDLIBS)

.PHONY: all clean
.PRECIOUS: %.o

clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)

