/*4.Question: Count even and odd elements
Question description: Write a C program to count how many even and odd numbers are in the array.
Sample data:
Input: 4 7 9 10 22
Expected output:
Even: 3
Odd: 2*/

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,sum=0,odd=0,even=0;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        even++;
        else if(a[i]%2!=0)
        odd++;
    }
    printf("odd:%d  even:%d\n",odd,even);
}