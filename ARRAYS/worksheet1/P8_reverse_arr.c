/*8.Question: Reverse an array
Question description: Write a C program to reverse an array in-place.
Sample data:
Input: 10 20 30 40 50
Expected output:
Reversed array: 50 40 30 20 10*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,j;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0,j=n-1;i<j;i++,j--)
    {
        int c=a[i];
        a[i]=a[j];
        a[j]=c;
    }
    printf("After reversing\n");
    for(i=0;i<n;i++)
         printf("%d ",a[i]);

}