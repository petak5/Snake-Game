#include <stdio.h>

void main() {
  int x, y;
  int stopx = 3;
  int stopy = 2;
  for (y = 0;y<stopy;y++) {
    
    printf("\n");
   }
   for (x=0;x<stopx;x++) {
       printf(" ");
    }
   printf("#");
   printf("\n");
  } //depending on OS, will need a clearscreen command ex: system("clear");
// This makes the grid for the single snake block to be located. to move left right add/subtract from stopx same goes for stopy
