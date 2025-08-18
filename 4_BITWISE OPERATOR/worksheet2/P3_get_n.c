/*3.Get nth bit of a number
Question: Write a C program to get the value of the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 2
Expected output: Bit 2 of 10 is 1*/

#include<stdio.h>
int get_nth(int x,int n)
{
    int i;
    return (x>>(n-1))&1;
}
int main()
{
    int x;
    printf("Enter the number\n");
    scanf("%d",&x);
    int n;
    printf("Enter the bit  position value\n");
    scanf("%d",&n);
    int v=get_nth(x,n);
    printf("The value of %dth bit is %d\n",n,v);
}