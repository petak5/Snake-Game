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

//
// TODO: test all the functions
//

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

/* returns a pointer to the last segment, the snake's tail */
segment* last_segment(snake s)
{
	snake tmp = s;
	while(tmp->next){
		tmp = tmp->next;
	}
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

/* append the new head position, remove the tail position */
void move_snake(snake s, int move_x, int move_y)
{
	segment *tmp = malloc(sizeof(segment));
	tmp->x = s->x + move_x;
	tmp->y = s->y + move_y;
	prepend(s, tmp);
	free(last_segment(s));
	last_segment(s) = NULL;
}
