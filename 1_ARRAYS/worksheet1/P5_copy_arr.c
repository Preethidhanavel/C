/*5.question: Copy array elements
Question description: Write a C program to copy all elements from one array to another.
Sample data:
Input: 1 2 3 4 5
Expected output:
Copied array: 1 2 3 4 5*/
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
    int b[n];
    for(i=0;i<n;i++)
    b[i]=a[i];
    for(i=0;i<n;i++)
    printf("%d ",b[i]);
}