/*
** hw1_io.c:
**
** The source file implementing output functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/


#include <stdio.h>
#include "hw1_io.h"

void write_polynomial3(double a0, double a1, double a2, double a3){


	int size=4;
	double arr[4]={a0,a1,a2,a3};
	double arr2[4]={a0,a1,a2,a3};
	int i,power;	

/*The definition of necessary variables. I used 2 arrays here.*/
/*Because while one keeps the real values, in the other the number*/
/*I kept it in the array by taking the mode according to the positive and negative state. * /
/*  So I kept the number by taking its modes in array [4].*/


	for(i=0;i<4;i++){

		if(arr[i] > 0){
			/* S* If the number is positive, the mode is taken according to 1.*/
			/*For example, if 5.0 is entered, this is to print 5. */

			while(arr[i] >= 1)
				arr[i] -= 1;
		}

		else if(arr[i] < 0){
			/* if the number is negative, the mode is taken according to -1.*/
			/*For example, if -4.0 is entered, this is to print -4.*/


			while(arr[i] <= -1)
				arr[i] += 1;
		}

		else{
			arr[i] = arr[i];
			/* / * If the number is zero, it is still equal to itself. */
		}
	}


	power = 3;
	// The for loop here x ^ 3 is used to print terms with x ^ 2.*/
	/* After each action, pow is reduced by 1, but the for loop is up to "size-2".*/
	/* goes. So since size = 4, the x ^ 2 term is printed last.*/


	for(i=0;i<size-2;i++){

		if(arr2[i] == 1.0){
			printf("+x^%d ",power);
			power--;
		}
		else if(arr2[i] == -1.0){
			printf("-x^%d ",power);
			power--;
		}
		else if(arr2[i] == 0.0){
			power--;
		}
		/* In the above blocks of if-else code, the special case coefficient*/
		/*It is checked if it is 1.0, -1.0 or 0.0. */

 		/* Other cases are checked in the else blog below */


		else{

			if(arr[i] == 0.0 && arr2[i] > 0){
				printf("+%dx^%d ",(int)arr2[i],power);
				power--;
			/* If the mode of the number is 0.0 and the number is positive, we understand that the integer is*/
			/*For example, 6.0, so the coefficients*/
			/*by casting that element to int in its array (array2 [])
			/*In the example here, it will print 6.*/

      				
			}

			else if(arr[i] == 0.0 && arr2[i] < 0){
				printf("%dx^%d ",(int)arr2[i],power);
				power--;
			/*	If the mode of the number is 0.0 and the number is negative then we understand that the integer*/
			/*For example, like -4.0.*/
			/*by casting that element to int in its array (array2 [])*/
			/*In the example here, it will print -4..     */
			}

			else if(arr2[i] > 0){
				printf("+ %.1fx^%d ",arr2[i],power);
				power--;
			/* If the mode of the number is not 0.0 (i.e. not an integer) and it is more than 0*/
			/*Because it is large, with the '+' operator.
			/*Entering 4.5 will print 4.5x ^% d. (% d == pow)*/

        
			}

			else{
				printf("%.1fx^%d ",arr[i],power);
				power--;
			
			/*Here we understand that the number is negative but not an integer.*/
			/*Like -3.2.*/

                  
			}
		}
	}

/*the same below expressions*/

	if(a2 == 1.0)
		printf("+x ");
	else if(a2 == -1.0)
		printf("-x ");
	else if(a2 == 0.0)
			;
	else{

		if(arr[2] == 0.0 && a2 > 0)
			printf("+%dx ",(int)a2);

		else if(arr[2] == 0.0 && a2 < 0)
			printf("%dx ",(int)a2);

		else if(a2 > 0)
			printf("+%.1fx ",a2);

		else
			printf("%.1fx ",a2);
	}


	if(a3 == 1.0)
		printf("+1 ");
	else if(a3 == -1.0)
		printf("-1 ");
	else if(a3 == 0.0)
			;
	else{

		if(arr[3] == 0.0 && a3 > 0)
			printf("+%d ",(int)a3);

		else if(arr[3] == 0.0 && a3 < 0)
			printf("%d ",(int)a3);

		else if(a3 > 0)
			printf("+%.1f ",a3);

		else
			printf("%.1f ",a3);
	}

	printf("\n");
}



void write_polynomial4(double a0, double a1, double a2, double a3, double a4){

	double array[5]={a0,a1,a2,a3,a4};
	double array2[5]={a0,a1,a2,a3,a4};
	int i,power;
	int size=5;

	/*the same below expressions*/


	for(i=0;i<5;i++){
	
		if(array[i] > 0){

			while(array[i] >= 1)
				array[i] -= 1;
		}

		else if(array[i] < 0){

			while(array[i] <= -1)
				array[i] += 1;
		}

		else{
			array[i] = array[i];
		}
	}


	power = 4;
	/*the same below expressions*/
	for(i=0;i<size-2;i++){

		if(array2[i] == 1.0){
			printf("+x^%d ",power);
			power--;
		}
		else if(array2[i] == -1.0){
			printf("-x^%d ",power);
			power--;
		}
		else if(array2[i] == 0.0){
			power--;
		}
		else{

			if(array[i] == 0.0 && array2[i] > 0){
				printf("+%dx^%d ",(int)array2[i],power);
				power--;
			}

			else if(array[i] == 0.0 && array2[i] < 0){
				printf("%dx^%d ",(int)array2[i],power);
				power--;
			}

			else if(array2[i] > 0){
				printf("+ %.1fx^%d ",array2[i],power);
				power--;
			}

			else{
				printf("%.1fx^%d ",array2[i],power);
				power--;
			}
		}
	}
/*for coefficient*/
	if(a3 == 1.0)
		printf("+x ");
	else if(a3 == -1.0)
		printf("-x ");
	else if(a3 == 0.0)
		;
	else{

		if(array[3] == 0.0 && a3 > 0)
			printf("+%dx ",(int)a3);

		else if(array[3] == 0.0 && a3 < 0)
			printf("%dx ",(int)a3);

		else if(a3 > 0)
			printf("+%.1fx ",a3);

		else
			printf("%.1fx ",a3);
	}


	if(a4 == 1.0)
		printf("+1 ");
	else if(a4 == -1.0)
		printf("-1 ");
	else if(a4 == 0.0)
		;
	else{

		if(array[4] == 0.0 && a4 > 0)
			printf("+%d ",(int)a4);

		else if(array[4] == 0.0 && a4 < 0)
			printf("%d ",(int)a4);

		else if(a4 > 0)
			printf("+%.1f ",a4);

		else
			printf("%.1f ",a4);
	}

	printf("\n");
}




