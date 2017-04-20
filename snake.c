/*
 *	a possible implementation of a snake as a linked list
 *	basic list functions 
 */

#include "snake.h"

/* list manipulation */
void prepend(snake sn, segment *sg)
{
	snake tmp = sn;
	sn->next = sg;
	sg->next = tmp;
}

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
