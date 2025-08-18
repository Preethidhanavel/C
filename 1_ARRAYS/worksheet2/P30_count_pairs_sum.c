/*30.Count pairs with given sum
Question description:
Write a C program to find number of pairs in the array whose sum is equal to a given value.
Sample data:
Input array: 1 5 7 -1 5 Sum = 6
Expected output:
Number of pairs: 3*/
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
    printf("Enter the sum\n");
    int sum,c=0;
    scanf("%d",&sum);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        if(a[i]+a[j]==sum)
        c++;
    }
    printf("The number of pairs are:%d\n",c);
}