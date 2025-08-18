/*10.Write a C program to determine whether a number is odd or even using bitwise operators.*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    if((n>>0)&1)
        printf("The given number is odd\n");
    else 
        printf("The given number is even\n");
}