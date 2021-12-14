#define N 2
 #include <stdio.h>
 #include<stdlib.h>
void arr_printer(int row,int column,int arr[][N]);
void arr_gen(int row,int column,int arr[][N]);
void randomer(int row,int column,int arr[][N]);
int up_or_down(unsigned int way,int r1,int c1,int row,int column,int arr[][N]);
int left_or_right(unsigned int way,int r1,int c1,int row,int column,int arr[][N]);
int isMatrixSorted(int row,int column,int arr[][N]);
enum which{
    to_exit=7,
    up=1,
    down=2,
    right=3,
    left=4
};

int main(){
 int i,j;
 int kontrol=1,kontrol2=0;
 int exit=1;
 int r,c;/*row,column*/
 int puz[N][N]={0};/*I initialized it by assigning zero to all elements of the array*/
 int temp[N][N]={0};/*I will compare this array with the original array at each stage and check if the game is completed.*/
 enum which way;
    

    arr_gen(N,N,puz);/*produce an ordered array*/
    
    for(i=0;i<N;i++){
             for(j=0;j<N;j++){
                temp[i][j]=puz[i][j];/*copy array for operations*/
             }
    }
    
     randomer(N,N,temp);/*Shuffle the array randomly*/
     arr_printer(N,N,temp);/*print first*/

    printf("please enter movement start location:(row column)\n");
    scanf("%d %d",&r,&c);
    printf("please enter the movement direction:\n(7exit/1up/2down/3left/4right):");
    scanf("%u",&way);
    
       if(way==1  || way==2){
               kontrol= up_or_down(way,r,c,N,N,temp);/*check if swap is done*/
           	   kontrol2=isMatrixSorted(N,N,temp);/*check if the puzzle is complete*/
        }
       else if(way==3  || way==4){
               kontrol=left_or_right(way,r,c,N,N,temp);
               kontrol2=isMatrixSorted(N,N,temp);/*same here with above*/

        }
        else if(way==7){
        	if(way==7){
        			printf("User selected exit happened\n");
        			return 0;
        		}
        }
  while(!kontrol2){
  		if(kontrol==0){/*If the action could not be done, get value again*/

                printf("This operation cannot be done, please try again.\n");
                printf("please enter movement start location:(row column) \n");
                scanf("%d %d",&r,&c);
                printf("please enter the movement direction\n(7exit/1up/2down/3left/4right):");
                scanf("%u",&way);
                
                if(way==7){
        				printf("User selected exit happened\n");
        				return 0;/*in case user would like to exit*/
        				break;
        		}
        		    if(way==1  || way==2){/*I'm doing the same checks again*/
               				kontrol= up_or_down(way,r,c,N,N,temp);
               				kontrol2=isMatrixSorted(N,N,temp);
            		}
            		else if(way==3  || way==4){
               				kontrol=left_or_right(way,r,c,N,N,temp);
               				kontrol2=isMatrixSorted(N,N,temp);
					}	
        }
            
        else if(kontrol!=0 ){/*If the process is done, check if the puzzle is completed. If not, get value again.*/ 
        		if(way==7){
        			printf("User selected exit happened\n");
        			return 0;/*in case user would like to exit*/
        			break;
        		}
        		arr_printer(N,N,temp);
        		printf("please enter movement start location:(row column)\n");
			    scanf("%d %d",&r,&c);
        		printf("please enter the movement direction\n(7exit/1up/2down/3left/4right):");
			    scanf("%u",&way);
			    
     			    if(way==1 || way==2){/*I'm doing the same checks again*/
            			   kontrol= up_or_down(way,r,c,N,N,temp);
        			       kontrol2=isMatrixSorted(N,N,temp);
      				}	
       				else if(way==3  || way==4){
               				kontrol=left_or_right(way,r,c,N,N,temp);
               				kontrol2=isMatrixSorted(N,N,temp);
       				}
        	continue;
        }
   }

 if(kontrol2!=0)/*if the whitespace character is at the bottom right and the array sorted like in the pdf function ends*/
  		printf("Puzzle has been solved\n");

  	
  	
}
 void arr_gen(int row,int column,int arr[][N]){
     
     int i,j,k=1;
    
     /*I assigned value to two-dimensional arrays from 1 to n * n*/
     for(i=0;i<N;i++){
         for(j=0;j<N;j++){
               if(i==N-1  &&  j==N-1)
                  break;/*In the mainfunction,since I initialize the array with 0 (it will be used in  space right bottom corner)I do not need a new assignment to that index.*/
               arr[i][j]=k++;
                
         }
     }
}
void randomer(int row,int column,int arr[][N]){
/*elements are randomly swapped, but time.h and srand should be used to be different each time, and we are not asked to use them in the homework */  
int i,j;
int temp,temprow,tempcol;
int rand_num;
    temprow=rand()%N;/*get the random index of row */
    tempcol=rand()%N;/*get the random index of column*/
    for(i=0;i<N;i++){
       for(j=0;j<N;j++){/* random swap */
              temp=arr[i][j];
              arr[i][j]=arr[temprow][tempcol];/*swap the desired element with the 'randomth' element*/
              arr[temprow][tempcol]=temp;
           
       }
     }
   
}
 
 
void arr_printer(int row,int column,int array[][N]){
int i,j,k;

 /*printing the number the format i am asked*/     
 	 for(k=0;k<6*N-(N-1);k++)/*After the arithmetic operations I did, I found the required number of stars.
 	 							 There is%-2d=   2space+2space = 4 characters for the row with the numbers and this is for 0th row break.*/
 	 	printf("*"); 
 	 printf("\n"); 

     for(i=0;i<N;i++){
             for(j=0;j<N;j++){
                 printf("*");
                 if(array[i][j]!=0)
                  	printf(" %-2d ",array[i][j]);/*-%2d is for satisfying true output*/
                 else 
                 	printf(" %-2c ",32);/*space character*/
                 if(j==N-1){
                 	printf("*\n");
                 	for(k=0;k<6*N-(N);k++){/*printing asterisks along the row and the last row break.*/
                 		printf("*");
                 	}
                 }
             }
             printf("*\n");
     }
}
/*
I didn't use switch cases because it would be nested and complicated the code*/
int left_or_right(unsigned int way,int r1,int c1,int row,int column,int arr[][N]){
/*I get the necessary indexes with r and c, I get the required direction with the direction.row and column are used to safely pass the 2-dimensional array to the function.*/
   int i,j;
   int maybe=0;/* to control*/
   int index1,index2;/* Temporary index in the function to avoid confusion when swapping elements*/
   int tmp;
   i=r1;
   		/*If the user wants to swap to the right direction, I check if there is a zero from the desired index to the end of the row.*/
        if(way==4){
                for(j=c1;j<N;++j){
                        if(arr[i][j]==0){
                            maybe++;
                            index1=i;
                            index2=j;/*I get an index where there is zero*/
                        }
                }
           		if(maybe!=0){/*I check if there is no zero in the row, if there is no zero, it will enter into else, not if,
            				 and the required value will be returned and the function will be terminated.*/
                		while(arr[r1][c1]!=0){
                	/*While the row index remains constant, the column index changes at every iteration, so I complete the desired swap.*/
                        			tmp=arr[index1][index2];
                                    arr[index1][index2]=arr[index1][index2-1];
                        			arr[index1][index2-1]=tmp;
                           			--index2;
                   		}
           		 }
            	else 
                		return maybe;/*If zero is found in the row, I return the same variable to indicate that it was found.*/
        }

        /*If the user wants to swap to the left, I check if there are zeros from the desired index to the beginning of the row.*/
        else if(way==3){
                for(j=c1;j>=0;--j){
                        if(arr[i][j]==0){
                            maybe++;
                            index1=i;/*I get an index where there is zero*/
                            index2=j;
                        }
                }
            	if(maybe!=0){/*I check if there is no zero in the line, if there is no zero, it will enter into else, not if,
            				 and the required value will be returned and the function will be terminated.*/
                		while(arr[r1][c1]!=0){
                /*While the row index remains constant, the column index changes at every iteration, so I complete the desired swap.*/			
                        		tmp=arr[index1][index2];
                                arr[index1][index2]=arr[index1][index2+1];
                        		arr[index1][index2+1]=tmp;
                          		++index2;
                    	}
             	}
            	else 
                		return maybe;
        }
       return maybe;/*If zero is found in the row, I return the same variable to indicate that it was found.*/
}
/*
I didn't use switch cases because it would be nested and complicated the code*/
int up_or_down(unsigned int way,int r1,int c1,int row,int column,int arr[][N]){
    int i,j;
    int maybe=0;
    int index1,index2;
    int tmp;
    j=c1;
    /*The only difference from the left_and_right function is that the row is changing while the column is fixed (for vertical swap).*/
        if(way==2){/*to up*/
                for(i=c1;i<N;++i){
                        if(arr[i][j]==0){
                            maybe++;/*got the index where 0 is found*/
                            index1=i;
                            index2=j;
                        }
                }
           		if(maybe!=0){/*I check if there is no zero in the column, if there is no zero, it will enter into else, not if,
            				 and the required value will be returned and the function will be terminated.*/
                		while(arr[r1][c1]!=0){
                	/*While the row index remains constant, the column index changes at every iteration, so I can complete the desired swap.*/
                        			tmp=arr[index1][index2];
                                    arr[index1][index2]=arr[index1-1][index2];
                        			arr[index1-1][index2]=tmp;
                           			--index1;
                   		}
           		 }
            	else 
                		return maybe;
        }


        else if(way==1){/*to down*/
                for(i=c1;i>=0;--i){
                        if(arr[i][j]==0){
                            maybe++;
                            index1=i;
                            index2=j;
                        }
                }
            	if(maybe!=0){
                		while(arr[r1][c1]!=0){
                        		tmp=arr[index1][index2];
                                arr[index1][index2]=arr[index1+1][index2];
                        		arr[index1+1][index2]=tmp;
                          		++index1;
                    	}
             	}
            	else 
                		return maybe;
        }
       return maybe;
}
 int isMatrixSorted(int row,int column,int arr[][N]){
 	int i=0,j=0;
	int check = 1;

while(i < N){
		while(j < N){
			if(i == N-1 && j == N-1){
				//do nothing
			}
			else if(j == N-1){
				if(arr[i][j] == 0 || arr[i+1][j] == 0){
					//don't check
				}
				else if(arr[i][j]>arr[i+1][0]){
					check=0;
				}
			}
			else{
				if(arr[i][j] == 0 || arr[i][j+1] == 0){
					//don't check
				}
				else if(arr[i][j]>arr[i][j+1]){
					check=0;
				}
			}
			j++;
		}
		i++;
	}
	return check;
}
	
	
	
