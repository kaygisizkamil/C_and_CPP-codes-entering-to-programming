#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define lineNO 20/*Each class will contain same amount of number ,class1 =10 class2=10*/
int main(){
    int control=2;
    double epsilon=0.000001;/*for comparing double variables*/
    double x,y;/*for using with equation */
    double slope;/*for finding slope*/
    double midX,midY;/*midpoint of the two classes(midx,midy)*/
    double noX=0,noY=0;/*taken from the user for classes, x and y*/
    int counter=-1;/*for finding line(n) n=counter*/
    double tempX1=0.0,tempY1=0.0,tempX2=0.0,tempY2=0.0;/*It will be equal to the averegeg point of the first and second classes.average point of class1=(tempx1,tempY1)*/
    int flag=1;
    while(flag==1){/*general loop (for counter checking)*/
            if(control==2 && flag==1){
    	counter++;/*counter, .lineNO created to print the line number and use in transactions*/
    		if(counter<=lineNO){/*for printing  line(counter)to class1 and class2 elements> .. */
       		printf("line %d >",counter);
        	}
        	else if(counter>lineNO  ){/*for printing  line(counter)to test elements> .. */
      			counter+=1;
       	 	printf("line %d >",counter);
     		}
        	while(control=scanf("%lf %lf",&noX,&noY)){/*As long as the user enters two variables*/
            		if(control==2 && flag==1){/*control if user entered two double variable or not i two scanf would turn 2*/
                        if(counter>lineNO-1){/*after taking class1 and class 2 element this section will find out which class the point belongs to*/
                            slope=(tempY2-tempY1)/(tempX2-tempX1);/*it will find the slope  thanks to avereage points of classs 1 and class 2*/
                            if(fabs(slope-epsilon)<0) slope+=epsilon;/*ý am using fabs for comparing two double variable*/
                        midX=(tempX1+tempX2)/2.0;/*the average point of two classes (x)*/
                        midY=(tempY1+tempY2)/2.0;
                        y=(-1.0/slope)*(x-midX)+midY;/*seperating line equation's -1/slope is used because seperating line's slope*average line's slope=-1*/
                        if(control==2 && flag==1){

                    		x=noX;/*assign noX to x which is taken from user for using it with equation and find out which class the points belong to*/
                    		y=noY;
                        if(fabs((y-midY)-(-1/slope)*(x-midX))<epsilon){/*if points are on the seperating line which
                            we did not assume ,program will be stopped*/
                            return 0;
                    		break;
                        }

                    		else if((y-midY)-(-1.0/slope)*(x-midX)>epsilon){/*y-y1>m(x-x1) noY-midY>-1/slope *(noX-midX)if that is true point belongs to class2*/
                   		     printf("line %d >class2\n",counter+1);
                     		     break;

                    		}

                		else if ((y-midY)-(-1.0/slope)*(x-midX)<0.000){ /*y-y1>m(x-x1) noY-midY>-1/slope *(noX-midX)if that is true point belongs to class2*/
                    			printf("line %d >class1\n",counter+1);/*counter +1 is used because line counter >a,b line counter+1>class X >line counter c,d*/

                            		break;

                    		}
                    	}
                	else if(control!=2){/*if two double value is not entered program execution will be stopped*/
                	flag=0;/*change flag value to 0 then loop condition will be not satisfied and loop will be stopped*/
                	break;}
                continue;/*Checking if the class assignment has finished, if not, this step is skipped*/


	  	}




           	 else if(counter <lineNO/2){/*We get points for class 1*/
                tempX1+=noX;
                tempY1+=noY;
                	if(counter==lineNO/2-1){
                	tempX1=tempX1/(lineNO/2);/*these will find he average point of class 1*/
                	tempY1=tempY1/(lineNO/2);

                	break;
                	}

                break;

                }

                else if(counter>=lineNO/2 && counter <=lineNO-1){/*we get points for class2*/


                tempX2+=noX;
                tempY2+=noY;
               	if(counter==lineNO-1){/*these will find he average point of class 2*/
               	tempX2=tempX2/(lineNO/2);
               	tempY2=tempY2/(lineNO/2);

               	break;
               	}
                break;



                }
                }






              else{
               flag=0;
               break;
               }


            }

            }
            else{/*if flag!=1 and control!=2 then program stops*/
                return 0;
                break;

            }

         }



}

