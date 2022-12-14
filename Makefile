CC = gcc
SRC = test-monty.c str_fun.c op_fun.c
DEPS = main.h
NAME = monty
FILE = 00.m
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.c: $(DEPS)

run:
	valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(FILE)

.PHONY: clean
clean: ; $(RM) ./$(NAME)
