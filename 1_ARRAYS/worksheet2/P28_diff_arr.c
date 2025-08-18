/*28.Find the difference of two arrays
Question description:
Write a C program to find the difference of two arrays (elements present in first array but not in second).
Sample data:
Array 1: 1 2 3 4 Array 2: 3 4 5 6
Expected output:
Difference (Array1 - Array2): 1 2*/

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
    scanf("%d",&a[i]);
    printf("Enter the array2 elements\n");
    for(i=0;i<m;i++)
    scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {      int c1=0;
            for(j=0;j<m;j++)
                if(a[i]==b[j]){
                    c1=1;
                    break;
                }
                if(!c1)
                printf("%d ",a[i]);

    }

}

