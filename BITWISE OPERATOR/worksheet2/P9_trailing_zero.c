/*9.Count trailing zeros in a binary number
Question: Write a C program to count the number of trailing zeros in the binary representation of a number.
Sample data: Input: 40 (binary 101000)
Expected output: Number of trailing zeros: 3*/
#include<stdio.h>
void trailing_zero(int n)
{
    int i,c=0;
    for(i=0;i<32;i++)
    {
        if((n>>i)&1)
            break;
            c++;
    }
    printf("The number of trailing zeroes is %d\n",c);
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    trailing_zero(n);
}