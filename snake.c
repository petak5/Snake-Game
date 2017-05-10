#define snake_max 10
//Starting an array for each of the positions of the snake
int direct = 3;
int snake_pos[11][11];
void endgame();
#define BOARD_X 40
void snake_move() {
	switch (direct) {
		case 1:
			if (snake_pos[1][0] == 1) {
				endgame(); }
			else {
				snake_pos[1][0] = snake_pos[1][0] - 1;}
			break;
		case 2:
			break;
		case 3:
			if (snake_pos[1][0] == BOARD_X) {
				endgame(); }
			else {
				snake_pos[1][0]++;
				printf("%d - %d",snake_pos[1][0], snake_pos[1][1] );}
			break;
		case 4:
			break;
	}
}

int snakelen() {
	int counter = 0;
	while (snake_pos[counter][1] != '\0') {
		counter++;
	}
	return counter;
}



