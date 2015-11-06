
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Wno-deprecated -Werror -Wstack-usage=1024 -o

problem1: problem1.c
	gcc $(CFLAGS) problem2 problem2.c
