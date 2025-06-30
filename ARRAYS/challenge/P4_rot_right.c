/*4. Rotate an array by 'k' positions to the right
Efficiently rotate an array of size n by k steps. Implement both brute force and optimized solutions (like reversal algorithm).

Example: Input: [1, 2, 3, 4, 5, 6, 7], k = 3
Output: [5, 6, 7, 1, 2, 3, 4]*/
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