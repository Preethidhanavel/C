/*2.Question: Sum of all elements in array
Question description: Write a C program to find the sum of all array elements entered by the user.
Sample data:
Input: 1 2 3 4 5
Expected output:
Sum = 15*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,sum=0;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
       sum+=a[i];
    printf("sum:%d\n",sum);
}