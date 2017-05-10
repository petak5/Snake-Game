#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.c"


	
struct termios rettonorm;


void entergamemode() {	// Sets the terminal in a non-return mode
	tcgetattr(STDIN_FILENO,&rettonorm);
//makes sure input and stuff isn't shown
	struct termios game = rettonorm;
	
	game.c_lflag &= ~(ECHO | ICANON);
	game.c_oflag &= ~(OPOST);
	game.c_iflag &= ~(ICRNL | IXON);
	game.c_cc[VMIN] = 0;
	game.c_cc[VTIME] = 10;// amout of time to give fro user to add input for read() inn tenths of sec
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &game);
}

void endgame() { //returns the terminal to regular
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &rettonorm);
	exit(0);
}

int main() {
	entergamemode();
	init_board();
	snake_pos[1][0] = 1; snake_pos[1][1] = 1; 
	char inp = '\0'; //initializing variable
	while (1) {
		pboard();				printf("x:%d - y:%d",snake_pos[1][0], snake_pos[1][1] );
		printf(" || direct:  %d \r\n", direct);		
		read(STDIN_FILENO, &inp, 1); //reads for 2 seconds
		switch (inp) { // Checks the character pressed
			case ('w'):
				printf("W\r\n");
				direct = 2;
				//printf("\r\n direct:  %d", direct);
				break;
			case ('a'): 
				printf("A\r\n");
				direct = 1;
				//printf("\r\n direct:  %d", direct);
				break;
			case ('s'): 
				printf("S\r\n");
				direct = 4;
				//printf("\r\n direct:  %d", direct);
				break;
			case ('d'): 
				printf("D\r\n");
				direct = 3;
				//printf("\r\n direct:  %d", direct);
				break;
			case (!(('w')||('a')||('s')||('d'))):
				system("wait .5");
				break;
		}
		snake_move();
    		system("clear");
	}
	endgame();
}
