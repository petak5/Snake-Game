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

int intersect_snake(snake s);
