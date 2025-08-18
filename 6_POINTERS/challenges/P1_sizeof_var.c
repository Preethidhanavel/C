/*1.How can you find the size of a data type without using the sizeof operator, using pointer arithmetic?*/
#include <stdio.h>

int main() 
{
    char *p1;
    char *p2;

    p1 = (char *)0;
    p2 = (char *)1;

    int size = (int)(p2 - p1);
    printf("Size of char = %d\n", size);

    int *i1 = (int *)0;
    int *i2 = (int *)1;
    size = (int)(i2 - i1);
    printf("Size of int = %d\n", size);

    float *f1 = (float *)0;
    float *f2 = (float *)1;
    size = (int)(f2 - f1);
    printf("Size of float = %d\n", size);

    double *d1 = (double *)0;
    double *d2 = (double *)1;
    size = (int)(d2 - d1);
    printf("Size of double = %d\n", size);

    return 0;
}
