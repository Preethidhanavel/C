//5.Using only a pointer (no array indexing), print all elements of the array.
#include<stdio.h>
int main()
{
    int a[4]={1,2,3,4};
    int* p=a;
    for(int i=0;i<4;i++)
    {
        printf("%d ",*p);
        p++;
    }
}