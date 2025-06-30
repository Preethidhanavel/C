/*4.Determine whether a given integer is a power of two using efficient bitwise operations.*/
#include<stdio.h>
void check_pow2(int n)
{
    int i,c=0;
    for(i=0;i<32;i++)
    {
        if((n>>i)&1)
            c++;
    }
    if(c==1)
        printf("The given number is a power of 2\n");
    else
        printf("The given number is not a power of 2\n");
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    check_pow2(n);
}