CC = gcc
SRC = test-monty.c get_opfun.c nodefunctions.c options.c options2.c aux_functions.c
DEPS = main.h
NAME = monty
TEST = ./test-files/
FILE = 0.m
FILE2 = 00.m
FILE3 = 000.m
FILE4 = 0000.m
FILE5 = 1.m
FILE6 = 11.m

CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.c: $(DEPS)

run: $(TEST)
	-valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST)$(FILE) 2> $(TEST)OUT/OUT1
	-valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST)$(FILE1) 2> $(TEST)OUT/OUT2
	-valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST)$(FILE2) 2> $(TEST)OUT/OUT3
	-valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST)$(FILE3) 2> $(TEST)OUT/OUT4
	-valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST)$(FILE4) 2> $(TEST)OUT/OUT5
	-valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST)$(FILE5) 2> $(TEST)OUT/OUT6
	-valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST)$(FILE6) 2> $(TEST)OUT/OUT7

.PHONY: clean
clean: ; $(RM) ./$(NAME)
