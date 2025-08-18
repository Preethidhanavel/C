/*7.Merge two sorted arrays without using extra space
Merge two sorted arrays A[] and B[] such that A contains the first n elements and B the rest, and after merging both are still sorted.

Example: Input: A = [1, 3, 5], B = [2, 4, 6]
Output: A = [1, 2, 3], B = [4, 5, 6] */

#include<stdio.h>
void sort_arr(int *a,int ele)
{int i,j,temp;
        for(i=0;i<ele;i++)
    {
        for(j=0;j<ele-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{ 
    int n,m;
    printf("Enter the number of elemets of array 1 and array 2:\n");
    scanf("%d%d",&m,&n);
    int a[n],b[m];
    int i,j=0;
     printf("Enter the array1 elements\n");
    for(i=0;i<m;i++)
        scanf("%d",&a[i]);
    printf("Enter the array2 elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    if(m==n){
        int c[100];
        for(i=0;i<m;i++)
            c[j++]=a[i];
        for(i=0;i<n;i++)
            c[j++]=b[i];
    sort_arr(c,j);
    for(i=0,j=0;i<m;i++)
        a[i]=c[j++];
    for(i=0;i<n;i++)
        b[i]=c[j+i];

    for(i=0;i<m;i++)
        printf("%d ",a[i]);
    for(i=0;i<n;i++)
        printf("%d ",b[i]);

    }
    else
        printf("The size doesn't match\n");

}