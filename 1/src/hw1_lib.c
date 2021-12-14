/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/

#include <stdio.h>
#include<math.h>
#include "hw1_lib.h"
#define f(x) (a0*x*x*x+a1*x*x+a2*x+a3)/*these two are created for root functions for prevent difficult to read*/
#define g(y) (a0*y*y*y*y+a1*y*y*y+a2*y*y+a3*y+a4)


double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{	
	double x;
	int i;
	double t=0;/*trapezoid(result)*/
	double deltax;
	double xi;
	double fx;
		
		deltax=(xe-xs)/delta;/*	Δx=(b−a)/n we have given n which is equal to delta in our integral3 function*/
		/*(for b to a) bIa ∫f(x)dx≈Tn=Δx/2[f(x0)+2f(x1)+2f(x2)+⋯+2f(xn−1)+f(xn)] is trapezoid rule*/
		/* xi=a+iΔx.*/
		/*xi is used for x0 in the f (x0) part, its value changes at every step and when it is equal to n, the process is completed.*/

		
		for(i=0;i<=delta;i++){
				xi= xs+i*deltax;
				x=  xi;
				fx= a0*x*x*x +a1*x*x + a2*x+a3;
				/*I divided the formula into three part to avoid confusion*/
				if(i==0){/*first is this Δx/2[f(x0)+..*/
					t+=(deltax/2)*(fx);
				}
				else if(i==delta){/*second is this Δx/2[2f(x1)+2(fx2)+....2(fxn-1)*/
					t+=(deltax/2)*(fx);

				}
				else/*third and last is this  Δx/2(....4f(xn))*/
					t+=(deltax/2)*(2*fx);


		}
		
		return t;
		printf("%f",t);

    return 0.0;
}


double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{/*the only thing different as the top is the degrees and coefficients no need to explain*/
/*https://www.math24.net/trapezoidal-rule*/
	double x;
	int i;
	double t=0;/*trapezoid(result)*/
	double deltax;
	double xi;
	double fx;
		
		deltax=(xe-xs)/delta;
		
		for(i=0;i<=delta;i++){
				xi= xs+i*deltax;
				x=  xi;
				fx= a0*x*x*x*x +a1*x*x*x + a2*x*x +a3*x +a4;

				if(i==0){
					t+=(deltax/2)*(fx);
				}
				else if(i==delta){
					t+=(deltax/2)*(fx);

				}
				else
					t+=(deltax/2)*(2*fx);

		}
		return t;
		printf("%f",t);



    return 0.0;
}
double root3(double a0, double a1, double a2, double a3, double xs, double xe)
{/*bisection method is used*/
	/*we have c=(b+a)/2 which is implemented as (xs+xe)/2*/
	double c;
    double f;   
 
    do{
        c=(xs+xe)/2;
        f=f(c);/*I used the  f (x) I defined above to make it easier and for preventing complexities*/
        if(f(xs)*f(c)<0){
            xe=c;/*assignment is done because if multiplying is less than 0  our new lower bound will be equal to c*/
        }
        else{
            xs=c;/*assignment is done because if multiplying is less than 0  our new upper bound will be equal to c*/
        }		/*after this assignment is done there is no need to create a new else if block because it contains all other possibilities*/
               
    }while(fabs(f(c))>0.001);/*I got the tolarance error this way, they were getting it around on the internet sources.*/
    return c;/*after exitting loop we obtain our roots which is equal to c*/
    
    return 0.0;
}
double root4(double a0, double a1, double a2, double a3, double a4, double xs, double xe)
{/*there we have nothing different but coefficients and degrees than above*/
    double c2;
    double g;

    do{
        c2=(xs+xe)/2;
        g=g(c2);
        if(g(xs)*g(c2)<0){
            xe=c2;
        }
        else{
            xs=c2;
        }
        
    }while(fabs(g(c2))>0.001);
    return c2;
    
    return 0.0;
}

