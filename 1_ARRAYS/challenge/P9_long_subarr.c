/*9.Find the longest subarray with equal number of 0s and 1s
Transform the problem using 0 → -1 and use hashmap to find the longest subarray with zero sum.

Example: Input: [0, 1, 0, 1, 1, 1, 0]
Output: Length = 6
*/
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
    int res = 0;
    for (int s = 0; s <n; s++) {
        int sum = 0;
        for (int e = s; e < n; e++) {
          	sum += (a[e] == 0) ? -1 : 1;
          
            if (sum == 0) 
              	if(e-s+1>res)
                    res =  e - s + 1;
        }
    }


printf("The maximum possible length is %d\n",res);
}
