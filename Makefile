
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Wno -depreciated -Wstack-usage=1024

problem2: problem2.c
	gcc -o problem2 problem2.c -I.
