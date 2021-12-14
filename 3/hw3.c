#include<stdio.h>
#include<math.h>/*gcc 1801042638.c -o 1801042638 -lm*/


void calculate_fibonacci_sequence();
void decide_perfect_harmonic_number();
void difference_max_min ();
void bmi_calculation ();
double find_max(double a,double b,double c,double d,double e);
double find_min(double a,double b,double c,double d,double e);

int main(){
calculate_fibonacci_sequence();
decide_perfect_harmonic_number();
difference_max_min ();
bmi_calculation();


	
}
void calculate_fibonacci_sequence(){
	int ctrl=1;/*counter will be incremented up to number*/
	int quantity;/*number provided by user*/
	int i=1,j=0;
	int nexT;
	int temp;/*to swap numbers*/
	int ctrl2;/*to control if number entered true format*/
	char ch;/*to help to control*/
		
	 	printf("Please enter term(s) number: ");
		scanf("%d",&quantity);
		ch=getchar();/*to check character-number distinction	*/

   while(ch!='*'){/*as long as user did not enter '*  */
   		if(ch=='\n'){/*if there is '\n' in buffer it means that we did read a number ,else there might be a character*/
   			ctrl2=quantity;/*I need to pre-assign it to enter the else if block below(line47).*/
   			if(quantity<=0){/*if the number which is provided by user is negative num*/
      		printf("Please enter “positive” term(s) number: ");
       		scanf("%d",&quantity);
          	ch=getchar();/*to check character-number distinction	*/
          	continue;/*continue the process*/
          	}
          	
        }
        else if(ch!='\n') {/*if there is no \n it means that we did not read a number ,entered value got caught by getchar*/
        	if(quantity==ctrl2){
        	printf("Please enter “numeric” term(s) number: ");
        	scanf("%d",&quantity);
        	ch=getchar();/*to check character-number distinction if i have read a character in second iteration there wont be a newline*/
        	continue;
        	}
        }
		while(ctrl<=quantity){
			if(j==0 ){
				printf("%d\n",i);/*for first term*/
				j+=i;
				if(quantity==1) 
					break ;/*if input equal to 1 then print and take a new input*/
				printf("%d\n",j);/*for second term*/
				if(quantity==2) 
					 break;/*if input equal to 2 then print and take a new input*/
				ctrl+=2;/*to control loop ı have first and second term therefore ctrl need to increment by 2*/
			}/*after first and second term other term changes iterative*/

			nexT=i+j;
			printf("%d\n",nexT);/*briefly first become second ,second become third and third become four,it iterates just like that*/
			temp=j;/*swap first(i) vs second(j)-second will become i*/
			j=i;
			i=j;/*swap completed*/
			i=nexT;/*swap second(i) vs third(nexT) -third will become i (no need to use temp because we dont have to save before values of them*/
			j=i;/*and so on*/
			i=temp;			
			ctrl++;/*counter*/
		}
		ctrl=1;/*reassign the values as long as user do not provide '*' , i have to execute these  operation  above*/
		i=1;
		j=0;

		printf("Please enter term(s) number: ");/*take an input again*/
		scanf("%d",&quantity);
		ch=getchar();

	}/*end of the process */

}




void decide_perfect_harmonic_number(){
	int num;
	int i;
	double counter=0.0;
	int ctrl=0;
	double ctrl2=0.0;
	
	char c;
	printf("please enter input number: ");
do{
scanf("%d",&num);	
c=getchar();
	if(num<0){
		printf("input must be a natural number , these part is over try again later");
		break;
	}
	if(c=='*')
		break;/*If I don't check it again, there was a problem with the output*/

printf("Natural Number Divisors; ");

	for(i=1;i<=num;i++){
		if(num%i==0 ){/*I found all divisors of the number*/
				if(num!=i){/*1 included, not including itself ,this check is for perfect because as mentioned in the definition*/
					ctrl+=i;
				}
			ctrl2+=1.0/(double)i;/*it is for Is Harmonic Divisor Number ,the reason I did tye casting is because if I hadn't, I would use integer arithmetic while using fmod below.*/
			counter++;/*I used this to find the dividing number in the nformula for harmonic divisor number*/
			if(num!=i)
				printf("%d, ",i);
			else /*to control last divisor if it is last do not print a comma ',' */
				printf("%d",i);

		}
	}
	ctrl2=counter/ctrl2;/*harmonic mean*/
	
	i= ((int)(ctrl2*100000)%100000);/* find the decimal part of harmonic mean precison is equal up to 5 digit after comma 0,00000h*/ 
								/*i used 'i' again because there is no need to waste of the memory,1 and 0 is not perfect number*/

	if(ctrl==num && num!=0 && num!=1)/* 0 and 1 are exception control num again*/
		printf("\nIs Perfect Number? : Yes");
	else if(ctrl!=num || num==0  || num==1)
		printf("\nIs Perfect Number? : No");

	if(i!=0 || num==0 )
		printf("\nIs Harmonic Divisor Number? : No"); /* 0 is not harmonic divisor*/
	else if(i==0 && num!=0 )
		printf("\nIs Harmonic Divisor Number? : Yes");
	

	
	 counter=0;/*Since I will use the values ​​until the user  enters '*' , I reassign them to their initial values.*/
	 ctrl=0;
	 ctrl2=0.0;
	 printf("\nplease enter input number: ");

}while(c!='*');/*function continue working until it gets the ‘*’ input*/
	
}




double find_max(double a,double b,double c,double d,double e){
double maximum;	/*Only one of the these can return 1(true). Others will return 0(false)*/

		maximum=a*(a >= b) * (a >= c)* (a >= d)*(a>=e)+/*if  the conditions  are satisfied  e.g first line(a>=b)*..) it will return 1 / true
													if first line satisfied a is greatest, it will return a*1*1*1 if not it'll control other lines*/
			b*(b > a) * (b >= c)* (b >= d)*(b>=e)+/* i did it like this (b>a) if i did (b>=a) would return a + b if a and b were equal*/
			c*(c > a) * (c > b) * (c >= d)*(c>=e)+ /*if i did c>=a and c>=b in case of c=b or c= a the return value would be different*/
			d*(d > a) * (d > b) * (d > c) *(d>=e)+/*and so on*/
			e*(e > a) * (e > b) * (e > c) *(e > d);

			return maximum;
			
}
double find_min(double a,double b,double c,double d,double e){
double minimum;
    minimum=a*(a <= b)*(a <= c)*(a <= d)*(a <= e)+/*if a is smallest it will return a*1*1*1	*/
			b*(b < a)*(b <= c)*(b <= d)*(b <= e)+/* i did it like this (b<a) if i did (b<=a) it would return a + b if a and b were equal*/
			c*(c < a)*(c < b)*(c <= d)*(c <= e)+/*if i did c<=a and c<=b in case of c=b or c=a the return value would be different than minimum*/
			d*(d < a)*(d <b)*(d < c)*(d <= e)+/*and so on ,i think my find_max and find_min function works same so i dont need to explain more*/
			e*(e < a)*(e < b)*(e < c)*(e < d);
			return minimum;
}


void difference_max_min (){
	double a,b,c,d,e;
	double temp;/*not to change real values and saving them for other purposes*/
	double max,min;
		printf("\nenter five number for comparison:\n");
		scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);
		
		max=find_max(a,b,c,d,e);
		min=find_min(a,b,c,d,e);
		/*I used fmod to avoid code redundancy, otherwise it can be done with type casting.*/
		temp=max;/*the reason behind i did this assign is keeping the max value for later use*/
		if(fmod(max,1)!=0.0)/*The reason I use the fmod is to check after the comma's digits  are equal to 0 or not.*/
			printf("Maximum number is:%f\n",temp);/*on ansi version %lf does not work*/
		else if(fmod(max,1)==0.0 )
			printf("Maximum number is:%d\n",(int)temp);/*If the number is equal to integer 458.00 or -5.00 assuming that 
								the user enters an integer and print the entered number as an integer like 458 5.*/
		

		temp=min;/*the reason behind i did this assign is keeping the max value for later use*/
		if(fmod(min,1)==0.0 )/*and same thing for min number*/
			printf("Minimum number is:%d\n",(int)temp);
		else if(fmod(min,1)!=0.0)
			printf("Minimum number is:%f\n",temp);
		
		temp=max-min;/*the reason behind i did this assign is Keeping the max and min value for later use*/
		if(fmod(max-min,1)!=0)
			printf("Difference between maximum and minimum is: %f\n",temp);
		else if(fmod(max-min,1)==0)
			printf("Difference between maximum and minimum is: %d\n",(int)temp);/*if difference is equal to integer format like 5 or 3 printing it as an integer
																			**in this function what im briefly doing is 
																			to check if user entered integer or double*/
}

void bmi_calculation(){
/*BMI = weight(kg) / height^2 (m)*/
float bmi;
float weight;
float height;
float epsilon;
	epsilon=0.0001;	/*to float comparison , not too necessary if compare part is deleted*/

	while(1){
		printf("\nplease enter weight(kg): ");
		scanf("%f",&weight);
		printf("\nplease enter height(m): ");
		scanf("%f",&height);
		bmi=weight/(height*height);

		if(weight-epsilon>0  && height-epsilon>0){/*if user do not provide realistic  number for weight and height like<0
													**epsilon is used for float comparison*/			
			if(bmi<16)
				printf("Your category:Severely Underweigh\n");
			else if(bmi>=16.0 && bmi<= 18.4)
				printf("Your category:Underweight\n");
			else if(bmi>=18.5 && bmi<= 24.9)
				printf("Your category:Normal\n");
			else if(bmi>=25.0 && bmi<= 29.9)
				printf("Your category:Overweight\n");
			else if(bmi>30)
				printf("Your category:Obese\n");
		break;			
		}
		else if(weight-epsilon<0  || height-epsilon<0){/*as long as the correct value is not entered, function will be working*/
			printf("there is no such a person that can be alive,\nplease try again\n");
			continue;/*It is free to use break and continue because loops are processed in class or at least i hope-remember so .this part can easily be
						 removed  if we  sure that user entered the true input */
		}
	}
}


