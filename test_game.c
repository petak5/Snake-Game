#include <stdio.h>
#include "board_prototype.h"
#include "snake.h"

int main(void)
{
	char  board[BOARD_Y][BOARD_X]; 
	snake my_sn, tmp_sn;
	int i;
	
	init_board(board);
	print_board(board);

	my_sn = create_segment(1, 1);
	board[my_sn->x][my_sn->y] = '#';
	//print_board(board);
	for (i = 0; i < 5; i++)
	{
		init_board(board);
		my_sn = move_snake(my_sn, i + 10, i + 20);
		tmp_sn = my_sn;
		board[tmp_sn->x][tmp_sn->y] = '#';
		while (tmp_sn->next != NULL)
		{
			tmp_sn = tmp_sn->next;
		}
		print_board(board);
	}

	return 0;
}