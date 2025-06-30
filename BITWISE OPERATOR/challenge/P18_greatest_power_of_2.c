/*18.Given a number N, find the greatest power of two that is less than or equal to N.*/

#include<stdio.h>

void power(int i)
{
    if((i & (i - 1)) == 0)
    {
        printf("It is a power of 2\n");
        return;
    }
    for(int k = i - 1; k >= 1; k--)
    {
        if((k & (k - 1)) == 0)
        {
            printf("Greatest power of 2 : %d\n", k);
            break;
        }
    }
}

int main()
{
    int i;
    printf("Input integer: ");
    scanf("%d", &i);
    power(i);
}
