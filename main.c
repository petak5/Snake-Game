#include <stdio.h>
#include <stdlib.h>
#include "userinput.h"


int main() {
	entergamemode();
	char input = '\0'; //initializing variable as null
	while (1) {
		get_input(&input);
		switch (input) { // Checks the character pressed, note "\r" is needed before "\n" to make a new line
			case ('w'):
				printf("W\r\n");
				break;
			case ('a'):
				printf("A\r\n");
				break;
			case ('s'): 
				printf("S\r\n");
				break;
			case ('d'): 
				printf("D\r\n");
				break;
		}
    	//system("clear");
	}
	endgamemode();
}