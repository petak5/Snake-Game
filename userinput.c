/*
 *	* functions to get input from user *
*/

char U = 'w',	/* defined valid input values */
     D = 's',
     L = 'a',
     R = 'd';

void get_input(char *input)	/* gets input from user */
{
  *input = getchar();
}


int check_input(char input)	/* checks if passed character is valid */
{			/* if valid return 1, otherwise return 0 */
  if (input == U || input == D || input == L || input == R)
    return 1;
  else
    return 0;
}


void set_direction(char snake_dir)	/* sets snake's new direction */
{

}


void update_direction(void)	/* complete function for our game */
{
  char new_direction;

  get_input(&new_direction);

  if (check_input(new_direction)) {

    set_direction(new_direction);
  }
}
