/*20.Given int *p = (int *)malloc(n * sizeof(int));, 
how would you access the 10th last element from the end using pointer arithmetic, 
assuming n is unknown but the end address is available?*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n = 20;
    int *p = malloc(n * sizeof(int));
    if (p == NULL) 
        return 1;

    for (int i = 0; i < n; i++) 
    {
        *(p + i) = i + 1;
    }

    int *end = p + n;
    int *tenth_last = end - 10;
    printf("%d\n", *tenth_last);

    free(p);
}
