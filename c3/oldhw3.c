#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE_2 250

int indexOfhor(FILE *fptr, const char *word, int *line, int *col);
int main(){
    FILE *fptr;
    FILE *fptr1;
    FILE *fptr2;
    int line ,col;

    char word[10];





    fptr = fopen("input.txt","r");
    fptr1= fopen("input2.txt", "r");
    fptr2= fopen("output.txt","a");

    while (fscanf(fptr, " %s", word) != EOF ) {

            rewind(fptr1);
             indexOfhor(fptr1, word, &line, &col );

                 if(line != -1 ){
                        fprintf(fptr2,"%s (%d,%d)\n", word, line + 1, col + 1);


                 }
                else if(line==-1) continue;


    }


    fclose(fptr);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
/* * Finds, first index of a word in given file. First index is represented* using line and column. */
//index of vertical is not completed on this code yet it will be edited soon
int indexOfhor(FILE *fptr, const char *word, int *line, int *col){
    char str[BUFFER_SIZE_2];
    char *pos;
    *line = -1;
    *col  = -1;

    while ((fgets(str, BUFFER_SIZE_2, fptr)) != NULL)
    {
        *line += 1;
         pos = strstr(str, word);
         if (pos != NULL){
            *col = (pos - str);
            break;
        }
    }
    // If word is not found then set line to -1
    if (*col == -1)
        *line = -1;
    return *col;
}

