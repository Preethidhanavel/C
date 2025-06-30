/*21.Question: Sum of even numbers
Question description: Write a C program to find the sum of all even numbers in an array.
Sample data:
Input: 2 3 4 5 6
Expected output:
Sum of even numbers: 12
*/

#include<stdio.h>
int main()
{
    int a[5],i,sum=0;
    printf("Enter the elements:\n");
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);

    for(i=0;i<5;i++)
    {
        if(a[i]%2==0)
        sum = sum + a[i];
    }
    printf("Sum of Even Numbers: %d\n",sum);
}