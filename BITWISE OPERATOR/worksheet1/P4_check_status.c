/*4.Write a program to check bit status in an integer:
Check if LSB is set (1) or not (0)
Check if MSB is set (1) or not (0)
Check if the nth bit is set (1) or not (0) (user input)*/

#include<stdio.h>
void check_lsb(int n)
{
    if((n>>0)&1)
        printf("LSB is set\n");
    else
        printf("LSB is not set\n");
}
void check_msb(int n)
{
    if((n>>31)&1)
        printf("MSB is set\n");
    else
        printf("MSB is not set\n");
}
void check_nbit(int n)
{
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    if((n>>pos)&1)
        printf("%d position is set\n",pos);
    else
        printf("%d position is not set\n",pos);
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    check_lsb(n);
    check_msb(n);
    check_nbit(n);
}
