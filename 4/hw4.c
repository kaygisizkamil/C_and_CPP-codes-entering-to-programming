#include <stdio.h>
#include<math.h>
void write_polynomial();
void palendrome_armstrong();
void prime_between();
//float rounder(float number);

int main(){
	write_polynomial();
	palendrome_armstrong();
	prime_between();
}
/*float rounder(float number){
****float i;
****	i=fmodf(number,i);
****		if(i<0.051)//Whatever the desired border is after the comma(e.g->0.051)
****			return number-i;
****		return number;//else return the number without changing anything
****
@@@@@@@ I think %.1f works as requested in pdf. It rolls down to the num0 if not greater or equal than 0.051 , but in case
@@@@@@@ if the conditions are not satisfied;
@@@@@@@ that function  provides the conditions clearly with a few minor adjustments by using round(num0) instead of num0 in the printf section.

}*/
void write_polynomial(){
float i,j,k,num0;//i represents the nth term,k represents degree,j and i will be used in condition statament 
printf("Enter your polynomial [n a_n a_n-1 a_n-2 ... a_0]: ");


	/*i<=j+2 because if we have a degree e.g 5 i'll take 7 values at the end; first degree, after coefficients(as much as degree+1) that is why i<=j+2*/
	
     for(i=1,j=2;scanf("%f",&num0),i<=j+2;i++){/*i settled scanf in test expression(condition) as long as condition does not satisfied it will evaluate values
        									no error checks were requested we assume that the user will enter the correct amount of numbers in the pdf.*/
            if(i==1){/*get the degree*/
                  j=num0;
                  k=j;
                continue;
            }
       
            if(i!=j+2 && i!=j+1 ){//section prints every term except the a0*x^0 and an*x^k and a1*x ​of the polynomial in the appropriate format
            	 if(i==2){//an*x^k (first)
                    if(num0>0){
                            if(num0==1)
                                printf("x^%.0f ",k--);
                            else 
                                printf("%.1fx^%.0f ",num0,k--);
                     }
                     else if(num0==0)
                          k--;/*do print nothing*/
                     else 
                        printf("%.1fx^%.0f ",num0,k--);
                 }
                 
                 else{//an−1 x^n−1 + ⋯ +
                     if(num0>0){
                            if(num0==1)
                                printf("+ x^%.0f ",k--);
                            else 
                                printf("+ %.1fx^%.0f ",num0,k--);
                     }
                     else if(num0==0)
                          k--;/*do print nothing*/
                     else 
                        printf("%.1fx^%.0f ",num0,k--);
                }
               
             }
               
             
            if(i==j+1){// this section arranges the previous step before last term  ,a1 x ^ 1 to not print x^1 only print x
                k--;//The 1 in a1x ^ 1 will not be printed,anyway  but power  must be reduced for the next term.
                if(num0>0){
                        if(num0==1)
                            printf("+ x ");
                        else if(num0!=1)
                            printf("+ %.1fx ",num0);
                }
                else if(num0==0)
                        ;/*do-print nothing*/
                else if(num0<0)
                        printf("%.1fx ",num0);
            
           }   
             
           else if(i==j+2){//it prints a0*x^0 without x^0, only x
                  if(num0>0)
                         printf("+ %.1f \n",num0);
                 else if(num0==0)
                        ;
                 else if(num0<0)
                         printf("%.1f \n",num0);
            break;/*after printing a0 exit the loop*/
            
            }
        }


 }

void palendrome_armstrong(){
int num,reversed=0,temp;
int ctrl1,ctrl2=0;//to control is num1,num2 satisfied the conditions;
int counter=0;//pow

	printf("\nPlease enter an integer: ");
	scanf("%d",&num);

		while(num<0){
				printf("\nPlease enter a positive integer: ");
				scanf("%d",&num);
		}
			
temp=num;/*Maintaining real value is generally important*/
	while(temp!=0){/*before reverse the num*/
		reversed=(reversed*10)+(temp%10);/*assume i've 513 ,first iteration reversed=3, second iteration 3*10 +1 
										,third iteration reversed=31*10 +5 and temp become 0 then exit loop*/
		temp=temp/10;
		counter++;
	}
	if(reversed==num)
		ctrl1=1;/*/*comparison between reversed number and actual number*/
	else ctrl1=0;

temp=num;/*Maintaining real value is generally important*/
reversed=0;/*For the following operations, there is no need for a new variable, I reset it and continue.*/
/*
**In the forum it was said that we can use the cube first, then the base of the digit,  then both.
The condition on the forum is satisfied if number has 5 digits first ^ 5 + .. last ^ 5 etc..

*/

	while(temp!=0){
		reversed+=pow(temp%10,counter);/*is armstrong num this conditon in pdf  changed by Ms.Ahi*/
		temp=temp/10;//if number has 4 digit control will be like first digit^4+..last digit^4
	}
	if(reversed==num)/*comparison between processed number and actual number*/
		ctrl2=1;
	else ctrl2=0;
	

	if(ctrl1==1	 		&&   ctrl2==1)
		printf("This number is both Palindrome and Armstrong number.\n");
	else if(  ctrl1==1	&&   ctrl2==0)
		printf("This number is only Palindrome number.\n");
	else if(  ctrl2==1	&&  ctrl1==0 )
		printf("This number is only Armstrong number\n");
	else if(ctrl1==0	&&   ctrl2==0)/*no need to curly braces '{' i think readability is better with this way*/
		printf("This number does not satisfy any special cases\n");
	

}

void prime_between(){

int num1,num2;
int i;
int ctrl;
int temp,sum=0;/*/*Maintaining real value is generally important temp is used for it*/
printf("\nPlease enter first integer number: ");
scanf("%d",&num1);
printf("Please enter second integer number: ");
scanf("%d",&num2);

while(num1<0	||	num2<0){
	printf("Please provide two positive number\n ");
	printf("Please enter first integer number: ");
	scanf("%d",&num1);
	printf("Please enter second integer number: ");
	scanf("%d",&num2);
}
if(num1>num2){/*if user entered  first number is bigger than second swap it to prevent error*/
	temp=num1;
	num1=num2;
	num2=temp;
}
  temp=num1+1;/*do not include starting number*/

  while(temp<num2){/*do not include finish number that is why < is used*/
	for(i=2;i<=temp/2;i++){/*this part finds is the number prime or not*/
		if(temp%i!=0){
			ctrl=1;/*if prime turn ctrl to 1*/
		}
		else{
			 ctrl=0;/*if not prime  turn ctrl to  0*/
			 break;
		}
	}
	
	if(ctrl==1){
		sum=sum+temp;/* if the number is prime then add it to sum*/
	}
	temp++;/*increase the value so next value can be controlled for in terms of prime*/
  }

printf("Sum of prime numbers between %d and %d is %d ",num1,num2,sum);
}
