#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC       1024/*max length of the line*/


typedef struct {            /* typedef for convenient use as type */
   double budget;
   int genre;
   char *name;
   double score;
   int year;
} Movie;


Movie *allocate_struct_array (Movie **parr, int total_line)
{
    return *parr = malloc (total_line * sizeof **parr);
}

int main (int argc, char **argv) {
/************************************line number******************************************/
 


    
    FILE *fileptr;
    int count_lines = 0;
    char chr;
    fileptr = fopen("Movies.txt", "r");
   /**extract character from file and store in chr*/
    chr = getc(fileptr);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fileptr);
    }
    fclose(fileptr); //close file.
/****************************************************************************************/
    int val;
    char buf[MAXC];                 /* temporary array to hold each line */
    int count = 0, 
        nparr = 0;
    Movie *parr = NULL;
    /* use filename provided as 1st argument (book.txt by default) */
    fileptr = fopen ("Movies.txt", "r");
    
    if (!fileptr) {     /* always validate file open for reading */
        perror ("fopen-fileptr");
        return 1;
    }
    
    if (!fgets (buf, MAXC, fileptr)) {  /* read/discard header line */
        fputs ("file-empty\n", stderr);
        return 1;
    }
    
    /* validate every allocation */
    if (allocate_struct_array (&parr, count_lines) == NULL) {
        perror ("malloc-parr");
        return 1;
    }
    
    while (nparr < count_lines) {       /* protecting allocation bounds */
        int ch = fgetc (fileptr);       /* ch must be type int */
        
        if (ch != '\n' && ch != EOF) {  /* if not \n and not EOF */
            buf[count++] = ch;          /* add char to buf */
            if (count + 1 == MAXC) {    /* validate buf not full */
                fputs ("error: line too long.\n", stderr);
                count = 0;
                continue;
            }
        }
        else if (count) {               /* only process buf if chars present */
            char *p = buf, *ep;         /* pointer & end-pointer */
            
            buf[count] = 0;             /* nul-terminate buf */
            
            /* locate 1st ',' with p and last ',' with ep */
            if ((p = strchr (buf, ',')) && (ep = strrchr (buf, ',')) && 
                p != ep) {  /* confirm pointers don't point to same ',' */
                size_t len = ep - p - 1;            /* get length of name */
                
                parr[nparr].name = malloc (len + 1);        /* allocate */
                if (!parr[nparr].name) {                    /* validate */
                    perror ("malloc-parr[nparr].name");
                    break;
                }
                
                /* separate buf & convert into budget, name, score -- validate */
                if (sscanf (buf, "%lf,%d,%[^,],%lf,%d", &parr[nparr].budget, &parr[nparr].genre, 
                            parr[nparr].name, &parr[nparr].score,&parr[nparr].year) != 5) {
                    fputs ("error: invalid line format.\n", stderr);
                    if (ch == EOF)                  /* if at EOF on failure */
                        break;                      /* break read loop */
                    else {
                        count = 0;                  /* otherwise reset count */
                        continue;                   /* start read of next line */
                    }
                }
            }
            nparr += 1;                             /* increment array index */
            count=0;                                /* reset count zero */
        }
        
        if (ch == EOF) {                            /* if EOF, now break */
            break;
        }
    }
    fclose(fileptr);                    /* close file */
    
    for (int i = 0; i < nparr; i++) {
        
        free (parr[i].name);            /* free strings when done */
    }
    free (parr);                        /* free struxts */
    /*
Only the text was read into dynamic name and the partition was made. Other parts could not be completed due to various problems.it will be added some day*/
}





























