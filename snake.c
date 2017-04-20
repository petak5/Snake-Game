/*
 *	a possible implementation of a snake as a linked list
 *	basic list functions 
 *
 *	snake works as a pointer to the whole structure, while segment represents a single tile,
 *	the (x, y) of each segment on the board, with a pointer(connection) to the next one
 *
 *	when i move the snake, instead of redoing the whole structure i simply add a new segment in the next position
 *	and delete the last segment, when the snake eats i just add the segment without removing anything
 *
 *	to check for intersections with itself i just check if the head(x,y) intersects with any segment, might work
 *	in the same way with the board
 */

#include "snake.h"

/* --- list manipulation --- */

/* adds a segment at the start */
void prepend(snake sn, segment *sg)
{
	snake tmp = sn;
	sn->next = sg;
	sg->next = tmp;
}

/* adds a segment at the end */
void append(snake sn, segment *sg)
{
	snake tmp = sn;
	while(tmp){
		tmp = tmp->next;
	}
	tmp->next = sg;
	sg->next = NULL;
}

/* returns 1 if snake intersects with itself */
int intersect_snake(snake s)
{
	snake tmp = s;
	while(tmp){
		if(s->x == tmp->x && s->y == tmp->y)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}
