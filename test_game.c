#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "userinput.h"
#include "board.h"
#include "snake.h"

int main(void)
{
	char  board[BOARD_Y][BOARD_X]; 
	char direction = '\0';
	snake my_sn, tmp_sn;
	int i;

	/* Create the start point which is always in the middle */
	my_sn = create_segment((BOARD_X % 2 == 0 ? BOARD_X / 2 : BOARD_X + 1 / 2), (BOARD_Y % 2 == 0 ? BOARD_Y / 2 : (BOARD_Y + 1) / 2));

	init_board(board);
	update_board(board, my_sn);
	print_board(board);

	while (1) {
		entergamemode();
		get_input(&direction);

		switch (toupper(direction)) {
			case('W'):
				printf("nice!\r\n");
				break;
		}
	}

	endgamemode();

	return 0;
}