/*39.Find product of all elements
Question description:
Write a C program to find the product of all elements in the array.
Sample data:
Input: 1 2 3 4
Expected output:
Product: 24*/

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
    int p=1;
        for(i=0;i<n;i++)
        p=p*a[i];

        printf("The product of array is %d\n",p);
}