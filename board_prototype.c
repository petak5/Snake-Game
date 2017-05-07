#include <stdio.h>

#define BOARD_X 80
#define BOARD_Y 40

void print_board(char board[][BOARD_X]);
void init_board(char board[][BOARD_X]);

// TEMP CODE
int main(void)
{
	char  board[BOARD_Y][BOARD_X]; 
	
	init_board(board);
	print_board(board);
	return 0;
}
// TEMP CODE


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