/*41.Find the minimum and maximum element using minimum comparisons
Question description:
Write a C program to find minimum and maximum elements using minimum number of comparisons.
Sample data:
Input: 1000 11 445 1 330 3000
Expected output:
Minimum element is 1 Maximum element is 3000*/
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

    int min,max;
    min = max = a[0];  

    for(i = 0; i < n; i++)
    {
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
    printf("min:%d max:%d\n",min,max);
}