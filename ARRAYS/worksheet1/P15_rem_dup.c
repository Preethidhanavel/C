/*15.Question: Remove duplicate elements
Question description: Write a C program to remove duplicate elements from an array.
Sample data:
Input: 2 3 2 4 3 5
Expected output:
Array after removing duplicates: 2 3 4 5
*/

#include<stdio.h>
int main()
{
    int i,j,k,n;
printf("Enter the number of elements \n");
scanf("%d",&n);    
int a[n];

    printf("Enter the Elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;)
        {
            if(a[i]==a[j])
            {
                for(k=j;k<n-1;k++)
                a[k]=a[k+1];
                n--;
            }
            else
            j++;
        }
    }
    
    printf("Array after removing duplicates:\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}