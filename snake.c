#define snake_max 10
//Starting an array for each of the positions of the snake
int direct = 3;
int snake_pos[11][11];
void endgame();

void snake_move() {
	switch (direct) {
		case 1:
			if (snake_pos[1][0] == 1) {
				endgame();
				 }
			else {
				snake_pos[1][0] = snake_pos[1][0] - 1;}
			break;
		case 2:
			if (snake_pos[1][1] == 1) {
				endgame(); }
			else {
				snake_pos[1][1] = snake_pos[1][1] - 1;}
			break;
		case 3:
			if (snake_pos[1][0] == (BOARD_X-2)) {
				endgame(); }
			else {
				snake_pos[1][0]++;
				//printf("x:%d - y:%d",snake_pos[1][0], snake_pos[1][1] );}
			break;
		case 4:
			if (snake_pos[1][1] == (BOARD_Y-2)) {
				endgame(); }
			else {
				snake_pos[1][1] = snake_pos[1][1] + 1;}
			break;
	}
}}

int snakelen() {
	int counter = 0;
	while (snake_pos[counter][1] != '\0') {
		counter++;
	}
	return counter;
}



