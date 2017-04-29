//check to see if the snake has hit the wall 
int wallcheck(posx,posy) { 
   if (posx >= BOARD_X || posx <= 0) {
      endgame();
   }
  else if (posy >=BOARD_Y || posy <=0) {
    endgame();
  }
  else {
    return 0
  }
