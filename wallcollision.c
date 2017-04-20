//check to see if the snake has hit the wall 
int void wallcheck(posx,posy) {
   if (--posx >= board_x || ++posx <= 0) {
      return 12
   }
  else if (--posy >=board_y || ++posy <=0) {
    return 12
  }
  else {
    return 0
  }
