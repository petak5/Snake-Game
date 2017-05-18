//object for snake to eat
int foodlocale;

void food_pos() {
	int posx;
	posx = snakelen() + (direct^4);
	posx = posx%38;
	board[posx][posx] = '#';
	foodlocale = posx;
}

void foodcheck() {
	if ((snake_pos[1][0] == foodlocale)&&(snake_pos[2][0]==foodlocale)) {
		food_pos();
		snake_add();
	}
}

