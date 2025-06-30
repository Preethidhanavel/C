/*1.Check Least Significant Bit (LSB) of a number is set or not
Question: Write a C program to check if the Least Significant Bit (LSB) of a number is set (1) or not.
Sample data: Input: 5 (binary 0101)
Expected output: LSB of 5 is set (1)*/
#include<stdio.h>
void check_lsb(int n)
{
    if((n>>0)&1)
        printf("LSB is set\n");
    else
        printf("LSB is not set\n");
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    check_lsb(n);
}