/*16.Check whether a number is even or odd using bitwise operator
Question: Write a C program to check whether a number is even or odd using bitwise AND operator.
Sample data: Input: 7
Expected output: 7 is odd*/
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