#define BOARD_X  40
#define BOARD_Y  20
char  board[BOARD_Y][BOARD_X]; 
#include "snake.c"
//board for the game



int snake_pos[11][11];
//start the board
void init_board() {
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
				board[y][x] = '0';
		}
	}
}

void snake_ins() {
	// get snakelength and set each val to that
	int xc,yc,xp,yp;	
	for (yc=0;yc<2;) {
		xc = yc + 1;
		xp = snake_pos[xc][yc];
		yc++;
		yp = snake_pos[xc][yc];
		board[yp][xp] = '#';		 
	}
}

// print the board
int  pboard()
{

	snake_ins();
	int x;
	int y;


	//display the board
	for(int y = 0; y < BOARD_Y; y++) {
		for(int x = 0; x < BOARD_X; x++) {
			printf("%c",board[y][x]);
		}
	printf("\r\n");
	}

	return 0;
}	
