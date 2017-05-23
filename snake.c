#define snake_max 10
//Starting an array for each of the positions of the snake
int direct = 3;
int snake_pos[40][40];
void endgame();
int lastpos[1][1];


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
	lastpos[0][0] = resx;
	lastpos[1][0] = resy;
	if (snakelen() == 1) {
		;}
	else {
		for (count=snakel;count>0;count--) {		
			snake_pos[1][count]=snake_pos[1][(count-1)];
			snake_pos[2][count]=snake_pos[2][(count-1)]; }
	}
}
			
void snake_add() {
	int tempx,tempy,i;
	tempx = lastpos[0][0];
	tempy = lastpos[1][0];
	i=snakelen();
	snake_pos[1][i] = tempx;
	snake_pos[2][i] = tempy;
}
			
void checkoverlap() {
	int i,resy,resx,resy2,resx2;
	int lim = snakelen()+1;
	resx = snake_pos[1][0];
	resy = snake_pos[2][0];
	for (i=1;i<=lim;i++) {
		resx2 = snake_pos[1][i];
		resy2 = snake_pos[2][i];
		if ((resy==resy2)&&(resx==resx2)) {
			endgame();
			 }
	}	
	if ((resx == lastpos[0][0]) && (resy == lastpos[1][0]))	{
		endgame(); }
}		
	

void snake_move() {
	switch (direct) {
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




