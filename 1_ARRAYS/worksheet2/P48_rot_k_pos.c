/*48.Rotate array by k positions
Question description:
Write a C program to rotate the elements of an array by k positions to the right.
Sample data:
Input: 1 2 3 4 5 k = 2
Expected output:
Output: 4 5 1 2 3*/
#include<stdio.h>

void main()
{
    
    int a[5],t,i,j, start,end,ele,n;

    ele = sizeof(a) / sizeof(a[0]);

    printf("Array: ");
    for(i = 0; i < ele; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Rotate right by:");
    scanf("%d",&n);


    for(i=0;i<n;i++)
    {
        start=a[ele-1];
        for(j=ele-1;j>0;j--)
        {
            a[j]=a[j-1];
        }
        a[0]=start;
    }
    printf("output:");
     for(i=0;i<ele;i++)
    {
        printf("%d ",a[i]);
    }





}