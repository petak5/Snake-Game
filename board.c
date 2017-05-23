#include <stdio.h>
#include "board_prototype.h"

/* prints an array */
/* WORKING */
void print_board(char board[][BOARD_X])
{
	int x;
	int y;
	for(int y = 0; y < BOARD_Y; y++) {
		for(int x = 0; x < BOARD_X; x++) {
			printf("%c",board[y][x]);
		}
	printf("\n");
	}
}

/* initializes array */
/* WORKING */
void init_board(char board[][BOARD_X])	/* it uses macro BOARD_X */
{
	int x;
	int y;

	//looping through the board
	for(int y = 0; y < (BOARD_Y); y++) {
		for(int x = 0; x < (BOARD_X); x++) {
			if ((x==0) || (x==(BOARD_X-1)))	
						board[y][x] = '|';
			else if ((y==0) || ((BOARD_Y-1)==y))
				board[y][x] = '-';
			else 
				board[y][x] = ' ';
		}
	}
}