/*24.Question: Split array into halves
Question description: Write a C program to split the array into two halves and print them separately.
Sample data:
Input: 1 2 3 4 5 6
Expected output:
First half: 1 2 3
Second half: 4 5 6*/


#include<stdio.h>

int main()
{
    int a[6];
    int i,j,temp,ele;
    ele=sizeof(a)/sizeof(a[0]);
    printf("input:");
    for(i=0;i<ele;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<ele/2;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i;i<ele;i++)
    {
        printf("%d ",a[i]);
    }

}