/* snake structure */
struct segment{
	int x;
	int y;
	struct segment *next;
};
typedef struct segment segment;
typedef segment* snake;
