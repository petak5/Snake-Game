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

/* returns a pointer to new segment */
/* WORKING */
segment* create_segment(int x, int y)
{
	segment *new = malloc(sizeof(segment));
	new->x = x;
	new->y = y;
	new->next = NULL;
	return new;
}

/* adds a segment at the beginning */
/* WORKING */
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
/* WORKING -> I think the first one satisfies our needs and is easy to use */
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
/* WARNING! USE WITH CAUTION :D */
void delete_segment(segment *sg)	// DON'T USE !! -> maybe we should just delete it
{
	free(sg);		// only sets x and y to 0
	sg = NULL;		// sets sg to nullbut the pointerwe wanna freeis still pointing to address in the memory
					// the function below works bcs it's setting the sg->next to NULL, not the sg
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

/* WORKING */
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
/* WORKING -> also has to return segment* bcs of prepend() */
segment* move_snake(snake s, int move_x, int move_y)		// MAYBE ADD intersect_snake() TO IT
{
	segment *tmp = create_segment(move_x, move_y);
	s = prepend(s, tmp);
	delete_last_segment(s);
	return s;
}

/* returns 1 if a segment is present on the given (x,y) */
/* WORKING */
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

	sg1 = create_segment(2, 20);
	sg2 = create_segment(3, 30);
	sg3 = create_segment(4, 40);

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

	int i;
	for (i = 5; i < 10; i++) {
		putchar('\n');
		my_sn = move_snake(my_sn, i, i * 10);
		tmp_sn = my_sn;
		printf("1. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
		tmp_sn = tmp_sn->next;
		printf("2. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
		tmp_sn = tmp_sn->next;
		printf("3. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
		tmp_sn = tmp_sn->next;
		printf("4. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	}

	if (check_snake(my_sn, 6, 60))
		printf("Found it\n");

	putchar('\n');
	append_xy(my_sn, 10, 100);				// both are the same
	append(my_sn, create_segment(10, 100));	// I like this one much more, maybe we should use just this and delete the new one

	tmp_sn = my_sn;
	printf("1. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	printf("2. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	printf("3. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	printf("4. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);
	tmp_sn = tmp_sn->next;
	printf("5. %p -> x = %d, y = %d\n", tmp_sn, tmp_sn->x, tmp_sn->y);

	snake_test1 = last_segment(my_sn);

	printf("Last segment: %p\n\tx = %d, y = %d\n", snake_test1, snake_test1->x, snake_test1->y);

	if (intersect_snake(my_sn))
		printf("You're dead\n");
	else
		printf("You're still alive\n");

	return 0;
}
