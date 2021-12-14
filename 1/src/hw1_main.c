/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/


#include <stdio.h>


#include "hw1_lib.h"
#include "hw1_io.h"



/*
** main function for testing the functions...
**
*/
int main(void) {
	write_polynomial3(7.0, -0.72, -4, 6.587 );
	write_polynomial4(11.2, 0, -7.44, -5.0, 3);
	printf("%f\n",integral3(11, 10, 5, -9, -10, 40, 10));
	printf("%f\n",integral4(11, 10, 5, -9, 3, -10, 40, 10));
	printf("%f\n",root3(4, -2, -7, 1, -2, 2));
	printf("%f\n",root4(2, 3, -11, -9, 15, -1,1 ));

	return (0);
} /* end main */
