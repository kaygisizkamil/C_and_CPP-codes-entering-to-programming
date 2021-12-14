#include <stdio.h>
#include <stdlib.h>
#define p1 0.5
#define p2 20

int main(void) {
    int k;
    double a, b, n;
    FILE *fin = NULL, *fout = NULL;

    fin = fopen("input.txt", "r");/*input file*/
    fout = fopen("output.txt", "w");/*output file*/

    fscanf(fin, "%lf", &a);/*There is at least one chunk in the sequence then this the first number of (first)chunk*/
    fprintf(fout, "%.4lf ", a);/*printing first number of chunk (a) */

    k = 1;/*counter-added number in a chunk */
    while(fscanf(fin, "%lf", &n) != EOF) {
        b = (double) (a * k + n) / (k + 1);/* b is instant average,a is general average
                                              k depends on whether n is added in the loop or not
                                              I used k + 1 because now we check whether the second number is chunked or not, because the first n was taken earlier
                                              The reason we made this assignment is that we cannot check without the first b*/

        if (!((b > a * (1 + p1)) || (b < a * (1 - p1)) || (a > n * p2) || (a < n / p2))) {
            a = (double) (a * k + n) / (k + 1);/*if condition is satisfied then make same assignment as above*/
            k++;/*the number of elements in any chunk will equal k, increase k as we assign*/
            fprintf(fout, "%.4lf ", n);/* then print the n we printed first (at above) , it will be like firstn secondn ..  */
        }
        else {
            fprintf(fout, "average: %.4lf\n", a);
            fprintf(fout, "%.4lf ", n);/* condition is not satisfied that is why we are  printing the number at newline as first number of new chunk*/
            a = n;/*Since it is the first number of the chunk, the average a is equal to n again, so a = n is assigned*/
            k = 1;/*chunk's number of elements is equal to 1 again so it is assigned to one*/
        }
    }

    fprintf(fout, "average: %.4lf\n", a);/*This assignment prints the average of the last chunk when there are no more numbers to add to the chunk, ie after all the numbers are finished.*/

    fclose(fin);
    fclose(fout);

    return 0;
}
