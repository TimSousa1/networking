SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .c .h .o

CC := gcc
CFLAGS = -O3

ifdef DEBUG
	CFLAGS = -ggdb -D DEBUG
endif

CFLAGS += -Wall -Wextra

SRC := $(shell find . -name '*.c')
OBJ := $(SRC:%.c=%.o)
DEPS := $(shell find . -name '*.h')
OUT_NAME := net.out

%.o : %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

$(OUT_NAME) : $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -r *.o $(OUT_NAME)
