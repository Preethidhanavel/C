/*15.Design a function that finds the intersection of two arrays using pointers.*/

#include<stdio.h>
int intersection(int *a,int n,int *b,int m,int *c)
{
         int i,k=0,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(a[i]==b[j])
                    c[k++]=a[i];
        }
        return k;
}
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
    int c[50];
    int k=intersection(a,n,b,m,c);
    for(i=0;i<k;i++)
    printf("%d ",c[i]);
}