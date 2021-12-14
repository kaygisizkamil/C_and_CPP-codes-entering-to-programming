/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
#include "hw2_lib.h"
void bottom_row(char border ,int width2);/*borders of the table for last row(bottom)*/
void top_row(char border,int width0);/*borders of the table for first (top) row*/
void row(char border,int width1);/*borders of the table for other rows 2-3-..*/
int is_true_data(int day, int month, int year);/*to control weekday of data*/


int is_true_data(int day, int month, int year){


 if(year>0){
        if(month>=1 && month<=12){
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                return 1;/*valid*/
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
                return 1;/*valid*/
            else if((day>=1 && day<=28) && (month==2))
                return 1;/*valid*/
            else if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0)))
                return 1;/*valid*/
            else
                return 2;/*day is invalid*/
        }
        else{
            return 2; /*month is invalid*/
        }
    }
    else{

        return 2; /*year is invalid*/
    }

}






int find_weekday_of_data(int day, int month, int year)
{
	   
/*January has thirty one days i.e 7*4+3 days therefore the day on first Feb will continually be three days sooner than the day on 1st january.
**february has twenty eight days..
**(excluding leap years) that is precise multiple of seven (7*4=28) thus there'll be no amendment within the month of march and it'll even be 3 days ahead of the day on 1st January of respective year
*Considering this pattern, if we have a tendency to produce an array of the leading variety of days for every month then it will incline as t[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}.
**Now allow us to explore the real case once there are leap years.Each four years, our calculation can gain one further day. Except every a hundred years when it doesn’t.
**Except every four hundred years when it does. however will we place in these adayitional days? simply adaying y/4 – y/100 + y/400. This adays precisely the needed variety of leap days. 
**however here could be a problem, the leap day is 29 Feb and not 0 January.This implies that this year mustn't be counted for the leap day calculation for the primary 2 months.
**Suppose that if the month were January or February, we subtracted one from the year. This suggests that in these months, the y/4 worth would be that of the 
**previous year and wouldn't be counted. 
**If we subtract 1 from the t[] values of each month once February this was going to happen.. that might fill the gap, and also the leap year downside is solved.That is, i'd like to create the
**subsequent changes: 
**1.t[] currently becomes {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}
**2.if m corresponds to Jan/Feb (that is, month<3) decrement y by 1
**3.the annual increment within the modulus is now y + y/4 – y/100 + y/400 in place of y. 
**in this code i am inspired by Sakamoto's Algorithm and gregorian calendar */
	int ctrl;
	/* array = number of days values */
	int which_day;
    int t[12]={ 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; /* if there were not any leap years t[] would be = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}*/
    ctrl=is_true_data(day, month, year);
  if(ctrl==1){/* it there is such a date */
    /* if month is less than 3 reduce year by 1*/ 
    if (month < 3) 
        year =year-1; 

    
     which_day= ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7); 
     if(which_day==0)/*I had to push the algorithm a little bit because it would return as zero on Sunday, if I didn't aday this condition*/
        which_day=7;
    return which_day;
   }
   else if(ctrl==2){/*if there is not such a day*/
   	printf("there is no such a date ,you need the execute the program again with true values(error)(exit)\n");
   	exit(1);
   }
 
}

int count_day_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year){

 /*i used shoe horn standard dating conventions , input values for month and year are shifted so that the calendar 'starts' in March instead of January.Therefore
 /I was able to solve the problems related to february 28-29 days and leap years with less code by starting the year one March
  /htts://en.wikipedia.org/wiki/Leap_year#Algorithm  ,The algorithm in the link was used*/
	int ctrl1,ctrl2;

	ctrl1=is_true_data(start_day, start_month, start_year);
	ctrl2=is_true_data(end_day, end_month, end_year);

if(ctrl1==2 || ctrl2==2){
	printf("wrong input (error)");
	exit(1);
}	
else if(ctrl1==1 && ctrl2==1){
start_month = (start_month + 9)%12;/*after i've implemented this, there were be no problem of calculating "days per month" and there is only 'days per year' to be calculated. */
start_year = start_year - start_month / 10;
start_day= 365*start_year + start_year/4 - start_year/100 + start_year/400 + (start_month*306 + 5)/10 + ( start_day - 1 );
                        /*  above part is for implementing leap year      */  
end_month= (end_month+ 9) % 12;
end_year= end_year- end_month/ 10;
end_day= 365*end_year+ end_year/4 - end_year/100 + end_year/400 + (end_month*306 + 5)/10 + ( end_day - 1 );
/*endmonth*306+5= it returns the number of days between March 1st, and the start of the 'm'th month after March*/
return end_day - start_day;
}




}



double find_angle(double a, double b, double c)
{
	double x,y;/*to describe medium length*/
	double alfa=0;/*angle(a) */
	double pi=acos(-1);/*to specify the value of pi via using trigonometric equality*/
	y=sqrt((b*b+a*a)/2 - (c*c/4)) /3;/*Suppose the center of edge of side c is 3y  divided into 2y and y, because of the median theorem a^2+b^2=2*vc^2/2+c^2 and formula became like that*/
	                                /*new triangle is going to be like 2y,2x,c*/
	x=sqrt((a*a+c*c)/2 - (b*b/4)) /3;/*Suppose the center of edge of side c is 3x divided into 2x and x, because of the median theorem a^2+b^2-2*a*b*cosalfa=c^2*/
	alfa=acos((4*x*x+4*y*y-a*a) / (8*x*y));/*With the cosine theorem, the angle is drawn from the angle-edge relationship*/
	return alfa; /*alfa is a unit of radian not angle*/

    return 0.0;
}
void top_row(char border ,int width0){/*borders of the table for first (top) row*/
    int i;
    if(border==42){/* if char border=='*'*/
   	 for(i=1;i<=width0;i++){ /*18*+36spaces=52+2corner character briefly width of row which is taken from print_tabulated function*/
      	  if(i==1){
        	    printf("┌");/*corner character*/
       	  }
        		printf("*");
       	  if(i==width0){
           	 printf("┐") ;             
            	printf("\n");
        	}	
   		 }	
   	}
   	else{/* if char border=='-' */
   		 for(i=1;i<=width0;i++){ 
      	  	if(i==1){
        		    printf("┌");/*corner character i did it this way because unsigned char a=191 printf("%c",a) prints>>? and this sign is not exactly what i want */
       	  	}
        			printf("-");
       	  	if(i==width0){
           			printf("┐") ;             
            		printf("\n");
        	}	
   		 }	
	}
  

}

void row(char border,int width1){/*borders of the table for other rows 2-3-..*/
        int i;
        if(border==42){/* if char border=='*'  */
      		for(i=1;i<=width1;i++){ /*18*+36spaces=54*/
        		printf("*");
        	if(i==width1)
                   printf("\n");
        	}
    	}
    	else{/* if char border=='-' */
    		for(i=1;i<=width1;i++){ /*18*+36spaces=54*/
        		printf("-");
        	if(i==width1)
                   printf("\n");
        	}

		}
}
void bottom_row(char border,int width2){/*borders of the table for last row(bottom)*/
    int i;
    if(border==42){
   	 	for(i=1;i<=width2;i++){ /*18*+36spaces=54*/
    	    if(i==1){
        	    printf("└");
        	}
       		 	printf("*");
        	if(i==width2){
            	printf("┘") ;             
            	printf("\n");
        }
    	}
	}
	else{
		for(i=1;i<=width2;i++){ /*18*+36spaces=54*/
    	    if(i==1){
        	    printf("└");
        	}
       		 	printf("-");
        	if(i==width2){
            	printf("┘") ;             
            	printf("\n");
        }
    	}

	}
    
}



void print_tabulated(unsigned int r11, double r12, int r13, 
                     unsigned int r21, double r22, int r23, 
                     unsigned int r31, double r32, int r33, char border)
{
	int i;
    int x,y;
   
	if(  floor (log10 (abs (r11)))+1>5	|| floor (log10 (abs (r21))) + 1>5 || floor (log10 (abs (r33))) + 1>5 ){/*controlling how many digits*/
		printf("you exceed the limit for first row ,compile and try again");
		exit(1);
	}
	 top_row(border,52);/*because of corner character im sending length of table -2*/  
            

                     for(y=0;y<=4;y++){
                            if(y==0){
                                printf("%c%11s\t%c%c%c%c%c%c%s%c%c%c%c%c%c%c%c%s%c%c%c\n",124,"Row 101",124,32,32,124,32,32,"Row ABCDEFG",32,32,124,32,32,124,32,32,"Row XYZ123",32,32,124);
                                /*124 is equal to '|'  in ascii table .32 is equal to ' '.(I'm printing vertical line sign '|' in tihs function to avoid confusion
                                and i changed to output table format little bit because you told us that  we don't have to stick to one output also at first in pdf there were no output
								**first's width is |4spaces+7(itself)+4spaces|  ,after | sign two spaces
								**second's width is |2spaces+11(itself)+2spaces|  ,after | sign two spaces
								**third's width  is |2spaces+10itself+2spaces|    
								**at the end there i have 54 character this is what length of table is going to be*/ 
                                row(border,54);
                            }
                            else if(y==1){
       
         		      /*(1,1)*/ printf("%c\t%-8d%c",124,r11,124);/*after \t (4space) i used To %-8d make the number left-aligned, a minus sign is adayed to the format specifier.
                                  To print a number 8spaces wide and left-justified (left-aligned) the format specifier is%-8d. */
                      /*(1,2)*/ printf("  %c%-15.3g%c",124,r12,124);/*suppose r12 2.7  After aligning it to the left, there remains 1space of 12 characters and 124 means the | sign*/
                      /*(1,3)*/ printf("  %c%+-14d%c\n",124,r13,124);
                                  row(border,54);
                            }
                            else if(y==2){
                                printf("%c\t%-8d%c",124,r21,124);/*(2,1)*/
                                printf("  %c%-15.3g%c",124,r22,124);
                                printf("  %c%+-14d%c\n",124,r23,124);
                                row(border,54);
                            }
                            else if(y==3){
                                printf("%c\t%-8d%c",124,r31,124);
                                printf("  %c%-15.3g%c",124,r32,124);
                                printf("  %c%+-14d%c\n",124,r33,124);
                                bottom_row(border,52);/*because of corner character im sending length of table -2*/
                                
                            }
                         
                    }
        
                                                                         
}



