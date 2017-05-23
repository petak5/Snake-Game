#include <unistd.h>
#include <termios.h> // an add in to edit the terminal settings. Im presuming only works on linux
#include <stdio.h>
#include <stdlib.h>
#include "board.c"


	
struct termios rettonorm;


void entergamemode() {	// Sets the terminal in a non-return mode
	tcgetattr(STDIN_FILENO,&rettonorm);
//makes sure input and stuff isn't shown
	struct termios game = rettonorm;
	
	game.c_lflag &= ~(ECHO | ICANON); //echo off. turno off output mode(canonical)
	game.c_oflag &= ~(OPOST);
	game.c_iflag &= ~(ICRNL | IXON);
	game.c_cc[VMIN] = 0;
	game.c_cc[VTIME] = 10;// amout of time to give fro user to add input for read() inn tenths of sec
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &game);
}

void endgame() { //returns the terminal to regular
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &rettonorm);//flushes the remaining input and returns the terminal settings tonormal
	exit(0);//exits safely
}

int main() {
	entergamemode();
	init_board();
	food_pos();
	snake_pos[1][0] = 1; snake_pos[2][0] = 1;//starts snake at origin

	char inp = '\0'; //initializing variable as null
	while (1) {
		pboard();/*print board*/				
		printf("x:%d - y:%d",snake_pos[1][0], snake_pos[1][1] );
		printf(" || direct:  %d || foodpos: %d \r\n", direct, foodlocale);	
		moveback();
		read(STDIN_FILENO, &inp, 1); //reads for 2 seconds(Sandard input into char inp, with length of 1)
		switch (inp) { // Checks the character pressed, note "\r" is needed before "\n" to make a new line
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
		}
		
		snake_move();
		foodcheck();
		checkoverlap();
    		system("clear");
	}
	endgame();
}
