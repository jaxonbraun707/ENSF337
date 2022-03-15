/* prog_two.c
 * ENSF 337 Lab 4 Exercise  E
 * Completed by: Jaxon Braun
 * Submission Date: October 20, 2021
 */

#include <stdio.h>
#include <limits.h>
#include "read_input.h"
#include "read_input.c"
#include "read_double.c"

#define SIZE 50

int main(void)
{
  double n = 0;
  char digits[SIZE];  

  int y = EOF;
  
  while (1)
    {
      printf("\n\nEnter an real number or press Ctrl-D to quit: ");
      y = read_real(digits, SIZE, &n); 
      if(y == 1)
	printf("\nYour real number value is: %f", n);
      else if(y == EOF){
	printf("\nGood Bye.\n");
	break;
      }
      else
	printf("\n%s is an invalid real rumber.", digits);
    }
    
  return 0;
}
