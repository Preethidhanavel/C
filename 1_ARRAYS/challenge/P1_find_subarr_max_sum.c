/*1. Find the subarray with the maximum sum (Kadane’s Algorithm)
Implement an efficient algorithm to find the contiguous subarray within a one-dimensional array of numbers that has the 
largest sum.

Example: Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6 (subarray: [4, -1, 2, 1])*/
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
    int res = a[0];
  	for(int i = 0; i < n; i++) {
    	int sum = 0;
        for(int j = i; j < n; j++) {
        	sum = sum + a[j];
          
            if(sum>res)
                res = sum;
        }
    }
    printf("The maximum is%d\n",res);
}