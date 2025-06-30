/*6.Question: Count negative elements
Question description: Write a C program to count total number of negative elements in an array.
Sample data:
Input: -1 3 -4 5 0 -7
Expected output:
Total negative elements: 3*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,c=0;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
       if(a[i]<0)
         c++;
    printf("Total negative elements:%d \n",c);
}