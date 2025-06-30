/*17.Write a function to calculate the dot product of two vectors using pointers.*/


#include<stdio.h>

int dotproduct(int *a,int *b,int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=(*(a+i))*(*(b+i));
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter vector size: ");
    scanf("%d",&n);
    int a[n],b[n];
    printf("Enter elements of vector 1:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter elements of vector 2:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int result=dotproduct(a,b,n);
    printf("dot product: %d\n",result);
    return 0;
}
