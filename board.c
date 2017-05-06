
//board for the game
#include <stdio.h>


#define BOARD_X  80
#define BOARD_Y  40



// Initializing the board
int  board()
{

	
	int x;
	int y;

	char  board[BOARD_Y][BOARD_X]; 
	//looping through the board
	for(int y = 0; y < (BOARD_Y); y++) {
		for(int x = 0; x < (BOARD_X); x++) {
			//even row
			if ((x==0) || (x==(BOARD_X-1)))	
						board[y][x] = '|';
			else if ((y==0) || ((BOARD_Y-1)==y))
				board[y][x] = '-';
			else 
				board[y][x] = '0';
		}
	}

	//display the board
	for(int y = 0; y < BOARD_Y; y++) {
		for(int x = 0; x < BOARD_X; x++) {
			printf("%c",board[y][x]);
		}
		printf("\n");
	}

	return 0;
}

int main(void)
{
	board();
	return 0;
}
