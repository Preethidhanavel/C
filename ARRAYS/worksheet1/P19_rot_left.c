/*19.Question: Left rotate array by n
Question description: Write a C program to rotate an array to the left by n positions.
Sample data:
Array: 1 2 3 4 5
Rotate by: 2
Expected output:
Rotated array: 3 4 5 1 2*/

#include<stdio.h>

int main()
{
    
    int a[5],t,i,j,start,ele,n;

    ele = sizeof(a) / sizeof(a[0]);

    printf("Array: ");
    for(i = 0; i < ele; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Rotate left by:");
    scanf("%d",&n);


    for(i=0;i<n;i++)
    {
        start=a[0];
        for(j=0;j<ele;j++)
        {
            a[j]=a[j+1];
        }
        a[ele-1]=start;
    }
       printf("output:");
     for(i=0;i<ele;i++)
    {
        printf("%d ",a[i]);
    }


}