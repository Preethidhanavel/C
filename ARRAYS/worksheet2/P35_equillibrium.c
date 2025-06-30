/*35.Find equilibrium index
Question description:
Write a C program to find the index where the sum of elements to the left is equal to the sum to the right.
Sample data:
Input: -7 1 5 2 -4 3 0
Expected output:
Equilibrium index is 3*/

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
    for (int i = 0; i < n; ++i) {
        int leftSum = 0;
        for (int j = 0; j < i; j++)
            leftSum += a[j];

        int rightSum = 0;
        for (int j = i + 1; j < n; j++)
            rightSum += a[j];

       
        if (leftSum == rightSum)
        {   printf("The equilibrium index is %d\n",i);       
            return 0;
        }
    }
  
}