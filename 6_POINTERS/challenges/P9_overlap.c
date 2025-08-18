//9.Design a program to find the overlapping part of two arrays using pointers.
#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter the number of elemets: array1 and array2\n");
    scanf("%d%d",&n,&m);
    int a[n],b[m];
    int i,j;
    printf("Enter the array1 elements\n");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    printf("Enter the array2 elements\n");
    for(i=0;i<m;i++)
        scanf("%d",b+i);

    int c[50],k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(*(a+i)==*(b+j))
                c[k++]=*(a+i);
        }
    }

    for(i=0;i<k;i++)
        printf("%d ",*(c+i));


}
