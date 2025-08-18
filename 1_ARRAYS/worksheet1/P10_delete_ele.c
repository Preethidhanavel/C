/*10.Question: Delete element at position
Question description: Write a C program to delete a number at a given position in an array.
Sample data:
Array: 10 20 30 40
Delete at position: 2
Expected output:
Array after deletion: 10 20 40*/

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,j;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int x;
    printf("Enter index position for deleting\n");
    scanf("%d",&x);
    for(i=x;i<n;i++)
    a[i]=a[i+1];
    for(i=0;i<n-1;i++)
    printf("%d ",a[i]);

}