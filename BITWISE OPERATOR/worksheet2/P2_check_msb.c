/*2.Check Most Significant Bit (MSB) of a number is set or not
Question: Write a C program to check if the Most Significant Bit (MSB) of a number is set (1) or not.
Sample data: Input: 128 (binary 10000000 for 8-bit number)
Expected output: MSB of 128 is set (1)*/
#include<stdio.h>
void check_msb(int n)
{
    if((n>>7)&1)
        printf("MSB is set\n");
    else
        printf("MSB is not set\n");
}
int main()
{
    char n;
    printf("Enter the number\n");
    scanf("%d",&n);
    check_msb(n);
}