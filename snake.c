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

segment* create_segment(int x, int y)
{
	segment* new = malloc(sizeof(segment));
	new->x = x;
	new->y = y;
	new->next = NULL;
	return new;
}

/* adds a segment at the beginning */
/* WORKING BUT WE HAVE TO RETURN THE VALUE LIKE THIS */
segment* prepend(snake sn, segment *sg)
{
	sg->next = sn;
	return sg;
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

/* appends a segment with given xy, returns 0 if a segment is already there */
int append_xy(snake sn, int x, int y)
{
	segment* p = sn;
	/* check each segment then append new at the end */
	while(p->next != NULL){
		if(p->x == x && p->y == y)
			return 0;
		else
			p = p->next;
	}
	
	/* might use append() too */
	segment* new = malloc(sizeof(segment));
	new->x = x;
	new->y = y;
	new->next = NULL;
	p->next = new;

	return 1;
}

/* returns a pointer to the last segment, the snake's tail */
/* WORKING */
segment* last_segment(snake s)
{
	if(s->next == NULL)
		return s;
	else
		return last_segment(s->next);
}

/* returns 1 if snake intersects with itself */
/* WORKING */
int intersect_snake(snake s)
{
	snake tmp = s->next;
	while(tmp){
		if(s->x == tmp->x && s->y == tmp->y)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

/* deletes the segment pointed by seg */
void delete_segment(snake sg)
{
	free(sg);
	sg = NULL;
}

/* deletes the last segment
 * could be used like
 *	if(ate food){
		move
	}
	else{
		move
		delete last
	}
 */
void delete_last_segment(snake s)
{
	snake p = s;
	while(p->next->next != NULL){
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
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

/* TEMP CODE */
/* Testing some functions */
int main(void)
{
	snake my_sn, tmp_sn, snake_test1, snake_test2;
	segment *sg1, *sg2, *sg3;

	my_sn = (segment *) malloc(sizeof(segment));

	my_sn->x = 1;
	my_sn->y = 10;
	my_sn->next = NULL;

	sg1 = (segment *) malloc(sizeof(segment));
	sg1->x = 2;
	sg1->y = 20;
	sg1->next = NULL;

	sg2 = (segment *) malloc(sizeof(segment));
	sg2->x = 3;
	sg2->y = 30;
	sg2->next = NULL;

	sg3 = (segment *) malloc(sizeof(segment));
	sg3->x = 4;
	sg3->y = 40;
	sg3->next = NULL;	

	my_sn = prepend(my_sn, sg1);
	my_sn = prepend(my_sn, sg2);
	my_sn = prepend(my_sn, sg3);

	tmp_sn = my_sn;
	printf("1. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	printf("2. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	printf("3. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	printf("4. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);

	snake_test1 = last_segment(my_sn);

	printf("Last segment: %p\n\tx = %d, y = %d\n", snake_test1, snake_test1->x, snake_test1->y);

	if (intersect_snake(my_sn))
		printf("You're dead\n");
	else
		printf("You're still alive\n");

	/*
	delete_segment(last_segment(my_sn));
	last_segment(my_sn)->next = NULL;		// IT DOESN'T SET THE POINTER TO NULL, IT JUST SETS X AND Y TO 0
												// THE POINTER STILL HAS ITS ADDRESS IN MEMORY INSTEAD OF NULL
	*/
	delete_last_segment(my_sn); // <- seems to work

	tmp_sn = my_sn;
	printf("1. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	printf("2. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	printf("3. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	//printf("4. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y); trying to avoid segfault
	printf("4. %p\n", tmp_sn);

	snake_test2 = last_segment(my_sn);

	printf("Last segment: %p\n\tx = %d, y = %d\n", snake_test2, snake_test2->x, snake_test2->y);

	return 0;
}
