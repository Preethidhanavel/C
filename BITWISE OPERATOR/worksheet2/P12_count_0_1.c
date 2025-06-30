/*12.Count total zeros and ones in a binary number
Question: Write a C program to count the total number of zeros and ones in the binary representation of a number.
Sample data: Input: 15 (binary 00001111)
Expected output: Number of ones: 4, Number of zeros: 4 (assuming 8-bit)*/

#include<stdio.h>
typedef unsigned char u8;

void binary(u8 n)
{
     int i;
        for(i=7;i>=0;i--)
            printf("%d",(n>>i)&1);
        printf("\n");
}
void count(u8 n)
{
    int i,z=0,o=0;
    for(i=0;i<8;i++)
    {
        if((n>>i)&1)
            o++;
        else if(!((n>>i)&1))
            z++;
    }
    printf("number os eroes:%d ones:%d\n",z,o);
}
int main()
{
    u8 n;
    printf("Enter the number\n");
    scanf("%d",&n);
    binary(n);
    count(n);
}