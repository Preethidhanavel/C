/*19.A number is called sparse if there are no two adjacent set bits in its binary representation. 
Check whether a given number is sparse.*/

#include <stdio.h>

int Sparse(int num) 
{
    return ((num & (num >> 1)) == 0);
}

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (Sparse(num))
        printf("%d is sparse\n", num);
    else
        printf("%d is NOT sparse\n", num);
}
