/*9.Reverse Array using Pointer Arithmetic
Task: Write a function that reverses an integer array in place using pointer arithmetic only (no array indexing).

Sample data:
1.int arr[] = {1, 2, 3, 4, 5};
Expected output:
Reversed array: 5 4 3 2 1*/

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
    int a[4]={1,2,3,4},i;
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