/*33.Find subarray with maximum sum (Kadane’s Algorithm)
Question description:
Write a C program to find the maximum sum of a contiguous subarray.
Sample data:
Input: -2 -3 4 -1 -2 1 5 -3
Expected output:
Maximum contiguous sum is 7*/
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