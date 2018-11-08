CC = cc
CFLAGS = -std=c99 -Wall -g
FILES = prompt.c example.c

build:
	$(CC) $(CFLAGS) $(FILES) -o example
