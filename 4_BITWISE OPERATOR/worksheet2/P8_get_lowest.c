/*8.Get lowest set bit of a number
Question: Write a C program to find the position of the lowest set bit in a number.
Sample data: Input: 18 (binary 10010)
Expected output: Lowest set bit of 18 is at position 1 (zero-based)*/
#include<stdio.h>
void find_lowest_set(int n)
{
    int i,min;
  for(i=31;i>=0;i--)
  {
    if((n>>i)&1)
    {
        min=i;
    }
  }
printf("The lowest set bit of %d is at position %d\n",n,min);
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    find_lowest_set(n);
}