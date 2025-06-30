/*6.Given an integer array, 
use pointer arithmetic to reverse it in place without using any index or size variables — just two pointers.*/

#include<stdio.h>
void rev(int*p,int*q,int n)
{
    int i,temp;
    for(i=1;i<n;i++)
        q++;
    for(;p<q;p++,q--)
    {
        temp=(*p);
        (*p)=(*q);
        (*q)=temp;
    }
}

int main()
{
    int *a,i,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    a=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int *p=a,*q=a;
    printf("Before Reversing:\n");
    for(i=0;i<4;i++)
        printf("%d ",a[i]);
    printf("\n");
    rev(p,q,4);
    printf("After Reversing:\n");
    for(i=0;i<4;i++)
        printf("%d ",a[i]);
}