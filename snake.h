#include <stdlib.h>

/* snake structure */
struct segment{
	int x;
	int y;
	struct segment *next;
};
typedef struct segment segment;
typedef segment *snake;

segment* create_segment(int x, int y);
segment* prepend(snake sn, segment *sg);
void append(snake sn, segment *sg);
int append_xy(snake sn, int x, int y);
segment* last_segment(snake s);
int intersect_snake(snake s);
void delete_segment(segment *sg);
void delete_last_segment(snake s);
segment* move_snake(snake s, int move_x, int move_y);
int check_snake(snake s, int x, int y);
