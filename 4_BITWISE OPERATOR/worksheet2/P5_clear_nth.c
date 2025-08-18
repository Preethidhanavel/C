/*5.Clear nth bit of a number
Question: Write a C program to clear (make 0) the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 3
Expected output: Number after clearing bit 3: 2 (binary 0010)*/
#include<stdio.h>

void binary(int n)
{
     int i;
        for(i=31;i>=0;i--)
            printf("%d",(n>>i)&1);
        printf("\n");
}
int clear_nbit(int n,int pos)
{
    n&=~(1<<pos);
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
    int n1=clear_nbit(n,pos);
    binary(n1);
    printf("After clearing : %d\n",n1);
}