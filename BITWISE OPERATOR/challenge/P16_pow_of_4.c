//16.Determine whether a given number is a power of four efficiently.

#include <stdio.h>

int fun(int num) 
{
    if (num <= 0)
        return 0;
    if ((num & (num - 1)) != 0)
        return 0;
    if ((num & 0x55555555) == 0)
        return 0;
    return 1;
}

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (fun(num))
        printf("%d is a power of 4\n", num);
    else
        printf("%d is NOT a power of 4\n", num);
    return 0;
}
