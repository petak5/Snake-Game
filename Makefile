PROGRAM=Snake-Game
CC=gcc
CFLAGS=-c -Wall

all: main snake board user_input link

link:
	$(CC) -o $(PROGRAM) main.o snake.o board.o user_input.o

main:
	$(CC) $(CFLAGS) main.c

snake:
	$(CC) $(CFLAGS) snake.c

board:
	$(CC) $(CFLAGS) board.c

user_input:
	$(CC) $(CFLAGS) user_input.c

clean:
	rm -rf *o

clean_all:
	rm -rf *o $(PROGRAM)
