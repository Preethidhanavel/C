/*26.Find the union of two arrays
Question description:
Write a C program to find the union of two arrays (all unique elements from both arrays).
Sample data:
Array 1: 1 2 3 4 Array 2: 3 4 5 6
Expected output:
Union: 1 2 3 4 5 6*/
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

    int c[100],k,c1;
    for(i=0;i<n;i++)
    c[i]=a[i];
    k=i;
    for(i=0;i<m;i++){
        for(j=0,c1=0;j<n;j++){
        if(a[j]==b[i]){
            c1=1; 
            break;
        }
        }
        if(!c1)
            c[k++]=b[i];
            
    }
    for(i=0;i<k;i++)
    printf("%d ",c[i]);


}

