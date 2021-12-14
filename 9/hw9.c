#include <stdio.h>
#define MAX 50

struct customer{
    char name[15];
    int age;
    int label;
    int is_deleted;/*flag*/
};
void swapper(struct customer *a){
    int c,d;
    struct customer tmp; 
      
    for (c = 0 ; c < MAX - 1; c++){/*I made the necessary swaps using the bubble sort algorithm, according to the label number, it is compared from beginning to end*/
        for (d = 0 ; d < MAX - c - 1; d++){/*Sorts the struct in ascending order until it reaches the kth label*/
          if (a[d].label > a[d+1].label){ /*e.g we got from user 0 3  5 will be ranked in ascending order, at the end of the swap 0 5 3 */
        	tmp=a[d];							/*if the max condition in the pdf is not satisfied this func will be called*/
            a[d]   = a[d+1];
            a[d+1] = tmp;
          }
        }
    }
}
void sequence_display(const struct customer *t, size_t count){
		printf("current sequence ");
        while( count-- ){
        	if(t->is_deleted==1)
                printf(" %d ", t->label);
                t += 1;
        }
}

int main(){
  struct customer book[MAX];
  int label0=0,label1=0,label2=0,label3=0,label4=0,label5=0;
  int select;
  int costumer=0;
  int i=0,j=0;

  for(i=0;i<MAX;i++){/*For the control mechanism, if the client is processed, is_deleted will be 0 if it is not processed, it will be 1, I initially made them all 0*/
  		book[i].is_deleted=0;
  		book[i].label=100;/*not necessary just to prevent possible crash(if it was not done  because of garbage value program might crash)*/
  	
  }
  i=0;
    printf("\n***********Banking System***********\n");
    printf("Current Sequence:");
    while(1){/*I did not add an exit condition because it is not wanted in the pdf, I assumed that it should work continuously, 
but I count the number of customers in the program.A cycle in the form of while (costumer) can be easily set up if desired.*/
        printf("\n1-Add customer\n2-Process customer\n");
        scanf("%d",&select);
        
            if(select==1){
            	if(label0<=4 && label1<=2  && label2<=2  && label3<=1  && label4<=1){/*if the condition is satisfied label0 might be max 5 label1 might be max 3 etc.*/
	                printf("Please enter the name of the customer : ");
	                scanf("%s",book[i].name);
	                printf("Please enter the age of the customer : ");
	                scanf("%d",&book[i].age);
	                printf("Please enter the label of the customer : ");
	                scanf("%d",&book[i].label);
	                book[i].is_deleted=1;/*make the flag 1 it means new customer is added*/ 
	                if(book[i].label==0)label0++;/*I keep counting each tag count to check later.*/
	                else if(book[i].label==1)label1++;/*increase the number of seats if the customer has been added*/
	                else if(book[i].label==2)label2++;
	                else if(book[i].label==3)label3++;
	                else if(book[i].label==4)label4++;
	                swapper(book);/*no need for address operator as in array.*/
	                sequence_display(book, sizeof book / sizeof *book);/*print the	  current sequence*/      
	                costumer++;
                    i++;
                    continue;
                 }
                 else if( label0>4 || label1>2  || label2>2  || label3>1  || label4>1){/*no need to swap because the number of kth labels that can be side by side is provided*/
/*If the conditions have reached the maximum, the newcomer is added to the end of the queue, because the condition in fairness and also homework requires*/
                 	printf("\nPlease enter the name of the customer : ");
	                scanf("%s",book[i].name);
	                printf("Please enter the age of the customer : ");
	                scanf("%d",&book[i].age);
	                printf("Please enter the label of the customer : ");
	                scanf("%d",&book[i].label);
	                book[i].is_deleted=1;
	                if(book[i].label==0)label0++;
	                else if(book[i].label==1)label1++;
	                else if(book[i].label==2)label2++;
	                else if(book[i].label==3)label3++;
	                else if(book[i].label==4)label4++;
	                
	                sequence_display(book, sizeof book / sizeof *book);	/*print current sequence*/ 
	                swapper(book);/*There is no need to swap before adding, 
	                				but if I do not swap again after adding, the program will not work properly after the added place until the last condition.*/       
                    i++;
                    costumer++;/*counting the number of customers*/
                    continue;
                 }

            }
              
            else if(select==2){
                    if(costumer==0){
                        printf("There is not any customer in bank system sequence.\n");
                        continue;
                    }

                    else{/*the first customer is processed every time user wanted so*/                        
		                 book[0].is_deleted=0;/*make the flag 0 it means new customer is processed*/ 
                    	 book[0].label=100;
                    	 if(book[0].label==0)label0--;/*decrease the number of seats if the customer has been added*/
			             else if(book[0].label==1)label1--;
			             else if(book[0].label==2)label2--;
			             else if(book[0].label==3)label3--;
			             else if(book[0].label==4)label4--;
                    	
                    	 printf("Proceed customer is %s\nCurrent Sequence:",book[0].name);
                    	  swapper(book);
                    	  for(j=0;j<=costumer;j++){
	                            if(book[j].is_deleted==1)
	                              printf(" %d ",book[j].label);/*printing current sequence i did not use sequence_display again because extra condition is required in here*/
                          }                     
                        costumer--;/*counting the number of customers*/
                        i--;
                        continue;
                    }                    
            }
            
            else{
                printf("invalid operation\n");
               
            }   
                
                
    }
}
