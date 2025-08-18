/*6.Write a C program to count the number of set bits in an unsigned integer.*/

#include<stdio.h>
int main()
{
    unsigned int n;
    printf("Enter the integer value\n");
    scanf("%d",&n);
    int i,c=0;
    for(i=31;i>=0;i--)
    {
        if((n>>i)&1)
        c++;
    }
    printf("The number of set bits in an unsigned integer is %d\n",c);
}