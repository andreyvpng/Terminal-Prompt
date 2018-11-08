CC = cc
CFLAGS = -std=c99 -Wall -g
FILES = prompt.c example.c

example:
	$(CC) $(CFLAGS) $(FILES) -o example
