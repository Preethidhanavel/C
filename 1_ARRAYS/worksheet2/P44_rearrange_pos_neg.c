/*44.Rearrange positive and negative numbers
Question description:
Write a C program to rearrange an array so that positive and negative numbers are placed alternatively.
Sample data:
Input: 1 2 3 -4 -1 4
Expected output:
Rearranged array: -4 1 -1 2 3 4*/

#include<stdio.h>

int main()
{
int ele;
    printf("Enter the number of elemets:\n");
    scanf("%d",&ele);
    int a[ele];
    int i,j=0,k=0,count;
    printf("Enter the array elements\n");
    for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
    int c[50],d[50];
    for(i=0;i<ele;i++)
        {
            if(a[i]<0)
            c[j++]=a[i];
        }
    for(i=0;i<ele;i++)
        if(a[i]>=0)
            d[k++]=a[i];
    for(i=0;i<ele;i++){
            if(i<j)
               printf("%d ",c[i]);
            if(i<k)
                 printf("%d ",d[i]);
    }
}