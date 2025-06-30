/*6.Toggle nth bit of a number
Question: Write a C program to toggle (flip) the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 1
Expected output: Number after toggling bit 1: 8 (binary 1000)*/
#include<stdio.h>

void binary(int n)
{
     int i;
        for(i=31;i>=0;i--)
            printf("%d",(n>>i)&1);
        printf("\n");
}
int toggle_nbit(int n,int pos)
{
    n^=(1<<pos);
    return n;
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    int pos;
    printf("Enter the bit position\n");
    scanf("%d",&pos);
    int n1=toggle_nbit(n,pos);
    binary(n1);
    printf("After clearing : %d\n",n1);
}