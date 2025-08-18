/*7.Get highest set bit of a number
Question: Write a C program to find the position of the highest set bit in a number.
Sample data: Input: 18 (binary 10010)
Expected output: Highest set bit of 18 is at position 4 (zero-based)*/

#include<stdio.h>
void find_highest_set(int n)
{
    int i,max;
  for(i=0;i<32;i++)
  {
    if((n>>i)&1)
    {
        max=i;
    }
  }
printf("The highest set bit of %d is at position %d\n",n,max);
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    find_highest_set(n);
}