#include <stdio.h>
void move(int numerx,int numery);
void main() {
    int xs;
    for (xs=0;xs<10;xs++) { 
         move(xs,0);
    }
 
}

void move(int numerx, int numery) {
  int x, y;
  int stopx = 1+numerx;
  int stopy = 1+numery;
  for (y = 0;y<stopy;y++) {
    
    printf("\n");
   }
   for (x=0;x<stopx;x++) {
       printf(" ");
    }
   printf("#");
   printf("\n");
   system("sleep 1");
   system("clear");
  } //depending on OS, will need a clearscreen command ex: system("clear");
// This makes the grid for the single snake block to be located. to move left right add/subtract from stopx same goes for stopy

    
