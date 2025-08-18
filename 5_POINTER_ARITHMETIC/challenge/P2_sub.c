//2.Consider two pointers p1 and p2 pointing inside the same array. 
//You are allowed to perform only subtraction between them. How can you find the number of elements between them?
#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int a[n];
    int i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    int *p1=&a[4];
    int *p=&a[1];
    printf("Number of Elements:%d\n",p1-p);
}