#define snake_max 10
//Starting an array for each of the positions of the snake
int direct = 3;
int snake_pos[11][11];
void endgame();



int snakelen() {
	int counter,ting;
	counter = 0;ting=0;
	while (snake_pos[1][counter++] != '\0') {
		ting++;
		}
	return counter - 1;
}

void moveback() {
	int count,resy,resx,snakel;
	snakel = snakelen()-1;
	resx = snake_pos[1][snakel];
	resy = snake_pos[2][snakel];
	board[resy][resx] = '0';
	if (snakelen() == 1) {
		;}
	else {
		/*	snake_pos[1][2]=snake_pos[1][1];
			snake_pos[2][2]=snake_pos[2][1];  //works to move three blocks
			snake_pos[1][1]=snake_pos[1][0];
			snake_pos[2][1]=snake_pos[2][0];	*/	for (count=snakel;count>0;count--) {		
			snake_pos[1][count]=snake_pos[1][(count-1)];
			snake_pos[2][count]=snake_pos[2][(count-1)]; }
	}
}
			
			
			
		
	

void snake_move() {
	switch (direct) {//need to implement a loop to sum all segments
		int snkl = snakelen(); int i;
		case 1:
			if (snake_pos[1][0] == 1) {
				endgame();
				 }
			else {
					snake_pos[1][0]--;}
			break;
		case 2:
			if (snake_pos[2][0] == 1) {
				endgame(); }
			else {
				snake_pos[2][0]--;
}
			break;
		case 3:
			if (snake_pos[1][0] == (BOARD_X-2)) {
				endgame(); }
			else {
					snake_pos[1][0]++; }
			break;
		case 4:
			if (snake_pos[2][0] == (BOARD_Y-2)) {
				endgame(); }
			else {
				snake_pos[2][0]++;}
			break;
		}
}



