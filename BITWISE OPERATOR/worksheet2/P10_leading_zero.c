/*10.Count leading zeros in a binary number
Question: Write a C program to count the number of leading zeros in the binary representation of a number (assuming 32-bit integer).
Sample data: Input: 16 (binary 00000000000000000000000000010000)
Expected output: Number of leading zeros: 27*/
#include<stdio.h>
void leading_zero(int n)
{
    int i,c=0;
    for(i=31;i>=0;i--)
    {
        if((n>>i)&1)
            break;
            c++;
    }
    printf("The number of leading zeroes is %d\n",c);
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    leading_zero(n);
}