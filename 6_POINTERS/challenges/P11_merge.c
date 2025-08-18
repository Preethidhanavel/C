/*11.Implement a function that merges two sorted arrays into a third array using pointers.*/


#include <stdio.h>

void mergesort(int *arr1,int n,int *arr2,int m,int *c)
{
    int *p1=arr1,*p2=arr2,*pc=c;

    int *end1=arr1+n,*end2=arr2+m;

    while(p1<end1 && p2<end2)
    {
        if(*p1<*p2)
            *pc++=*p1++;
        else
            *pc++=*p2++;
    }
    while(p1<end1)
        *pc++=*p1++;
    while(p2<end2)
        *pc++=*p2++;
}

int main()
{
    int n,m;
    printf("enter size of first array: ");
    scanf("%d",&n);
    int arr1[n];
    printf("enter elements of first array:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr1[i]);

    printf("enter size of second array: ");
    scanf("%d",&m);
    int arr2[m];
    printf("Enter elements of second array:\n");
    for(int i=0;i<m;i++)
        scanf("%d",&arr2[i]);

    int c[n+m];
    mergesort(arr1,n,arr2,m,c);

    printf("merged array:");
    for(int i=0;i<n+m;i++)
        printf(" %d",c[i]);
    printf("\n");

    return 0;
}
