/*11.Flip bits of a binary number using bitwise operator
Question: Write a C program to flip all bits of a number using bitwise operators.
Sample data: Input: 5 (binary 00000101)
Expected output: Flipped bits: 250 (binary 11111010) (assuming 8-bit)*/
#include<stdio.h>
typedef unsigned char u8;
void binary(u8 n)
{
     int i;
        for(i=7;i>=0;i--)
            printf("%d",(n>>i)&1);
        printf("\n");
}
void flip_bits(u8 n)
{
    int i;
    for(i=0;i<8;i++)
    {
        n^=(1<<i);
    }
 binary(n);
 printf("After flipping %d\n",n);
}
int main()
{
    u8 n;
    printf("Enter the number\n");
    scanf("%d",&n);
    flip_bits(n);
}