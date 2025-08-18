/*20.Question: Right rotate array by n
Question description: Write a C program to rotate an array to the right by n positions.
Sample data:
Array: 1 2 3 4 5
Rotate by: 2
Expected output:
Rotated array: 4 5 1 2 3*/

#include<stdio.h>

int main()
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