/*14.Convert decimal to binary using bitwise operator
Question: Write a C program to convert a decimal number to binary representation using bitwise operators.
Sample data: Input: 13
Expected output: Binary representation: 1101*/

#include<stdio.h>
typedef unsigned char u8;
void binary(u8 n)
{
     int i;
        for(i=7;i>=0;i--)
          printf("%d",(n>>i)&1);
        printf("\n");
}

int main()
{
     u8 n;
    printf("Enter the number\n");
    scanf("%d",&n);
    binary(n);

}