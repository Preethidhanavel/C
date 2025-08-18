/*13.Question: Merge two arrays
Question description: Write a C program to merge two arrays into a third array.
Sample data:
Array 1: 1 2 3
Array 2: 4 5 6
Expected output:
Merged array: 1 2 3 4 5 6 */

#include<stdio.h>
int main()
{ int n,m;
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
    int c[100];
    for(i=0;i<m;i++)
        c[j++]=a[i];
    for(i=0;i<n;i++)
        c[j++]=b[i];

    printf("Merged Array:\n");
    for(i=0;i<(m+n);i++)
        printf("%d ",c[i]);
}