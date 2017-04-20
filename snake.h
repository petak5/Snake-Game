/* snake structure */
struct segment{
	int x;
	int y;
	struct segment *next;
};
typedef struct segment segment;
typedef segment *snake;

void prepend(snake sn, segment *sg);
void append(snake sn, segment *sg);
segment* last_segment(snake s);
int intersect_snake(snake s);
void move_snake(snake s, int move_x, int move_y);
