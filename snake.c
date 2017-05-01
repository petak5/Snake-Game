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
//		 check if function's parameter isn't NULL !!
//

#include "snake.h"
#include <stdio.h>	// THIS IS HERE JUST FOR TESTING PURPOSES

/* --- list manipulation --- */

/* adds a segment at the beginning */
void prepend(snake sn, segment *sg)
{
	snake tmp = sn;
	sn = sg;
	sn->next = tmp;
}

/* adds a segment at the end */
/* WORKING */
void append(snake sn, segment *sg)
{
	snake tmp = sn;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = sg;
	sg->next = NULL;
}

/* returns a pointer to the last segment, the snake's tail */
// NEED TO FIX, INFINITE LOOP -> possible solution down there
// did it from scratch in a recursive fashion, still broken -> segfault, i feel dumb
segment* last_segment(snake s)
{
	if(s->next == NULL)
		return s;
	else
		return last_segment(s->next);
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

/* deletes the segment pointed by seg */
void delete_segment(snake seg)
{
	free(seg);
	seg = NULL;
}

/* append the new head position, remove the tail position */
void move_snake(snake s, int move_x, int move_y)
{
	segment *tmp = malloc(sizeof(segment));
	tmp->x = s->x + move_x;
	tmp->y = s->y + move_y;
	prepend(s, tmp);
	delete_segment(last_segment(s));
}

/* returns 1 if a segment is present on the given (x,y) */
int check_snake(snake s, int x, int y)
{
	snake tmp = s;
	while(tmp){
		if(tmp->x == x && tmp->y == y)
			return 1;
		else
			tmp = tmp->next;
	}
	return 0;
}

// MY TESTING SETUP :D, can't figure out what am I doing wrong, will continue tomorrow
// you're accessing tmp_sn->next members while it's NULL

/* TEMP CODE */
/* Testing some functions */
int main(void)
{
	snake my_sn, tmp_sn;
	segment *new_sg;

	printf("1\n");

	my_sn = (segment *) malloc(sizeof(segment));

	my_sn->x = 10;
	my_sn->y = 20;
	my_sn->next = NULL;

	printf("2\n");

	new_sg = (segment *) malloc(sizeof(segment));
	new_sg->x = 15;
	new_sg->y = 30;
	new_sg->next = NULL;

	printf("3\n");

	prepend(my_sn, new_sg);

	printf("4\n");

	printf("%p - %p\n", my_sn, my_sn->next);
	tmp_sn = my_sn;
	printf("1.: x = %d, y = %d\n", tmp_sn->x, tmp_sn->y);
	my_sn->next = new_sg; //<- FIXED with this line
	tmp_sn = tmp_sn->next;
	printf("2.: x = %d, y = %d\n", tmp_sn->x, tmp_sn->y);

	printf("5\n");

//	snake test = last_segment(my_sn); <- still broken

	return 0;
}
