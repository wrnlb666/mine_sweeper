CC = gcc
CFLAG = -Wall -Wextra -g
OBJ = *.o
SRC = ./src

.PHONY: map test

all: map test

map: $(SRC)/map.c $(SRC)/map.h
	$(CC) $(CFLAG) $< -c

test: $(SRC)/test.c
	@ \
		$(CC) $(CFLAG) $(OBJ) $< -o $@; \
		./test
