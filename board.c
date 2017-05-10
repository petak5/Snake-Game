#include "snake.c"
//board for the game


#define BOARD_X  40
#define BOARD_Y  20
int snake_pos[11][11];


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
	// get snakelength and set each val to that
	int xin,yin,lin,yarr,xarr;
	lin = 1;
	yarr=0;
	xarr = 1;
	yin = 0; xin = 1;
	int snake_buf = 1 + snakelen();
	while (yarr<2) {
		yin = snake_pos[xarr][yarr];
		xin = snake_pos[xarr][yarr];
		printf("//%d, %d// ", xin, yin);	
		board[xin][yin] = '#';
		if (lin == 1) {
			yarr++;
			lin = 2;
		}
		else if (lin ==2) {
			xarr++;
			lin = 1;
		}
	}







	//display the board
	for(int y = 0; y < BOARD_Y; y++) {
		for(int x = 0; x < BOARD_X; x++) {
			printf("%c",board[y][x]);
		}
	printf("\r\n");
	}

	return 0;
}	
