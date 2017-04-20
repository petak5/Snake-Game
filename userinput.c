/*
 *	* functions to get input from user *
*/

char get_input(void)	/* gets input from user */
{
  return (getchar());	/* returns character from user */
}


int check_input(char)	/* checks if passed character is valid */
{			/* if valid return 1, otherwise return 0 */

}


void set_direction(char snake_dir)	/* sets snake's new direction */
{

}


void update_direction(void)	/* complete function for our game */
{
  char new_dir;

  new_dir = get_input();

  if (check_input(new_dir)) {

    set_direction(new_dir);
  }
}
