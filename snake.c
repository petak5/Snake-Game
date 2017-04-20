/*
 *	a possible implementation of a snake as a linked list
 *	basic list functions 
 */

/* snake structure */
struct segment{
	int x;
	int y;
	struct segment *next;
};
typedef struct segment segment;
typedef segment* snake;
