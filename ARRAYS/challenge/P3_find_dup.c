/*3.Find the duplicate number in an array of n+1 integers (each from 1 to n)
Use Floyd’s Cycle Detection or other space-efficient methods to detect a repeated number in the array without modifying the input.

Example: Input: [3, 1, 3, 4, 2]
Output: 3*/

#include<stdio.h>

int main()
{
int ele;
    printf("Enter the number of elemets:\n");
    scanf("%d",&ele);
    int a[ele];
    int i,j=0,k=0,count;
    printf("Enter the array elements\n");
        for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
int c;
for(i=0;i<ele;i++)
        {
                for(j=0;j<i;j++) {
                        if(a[i]==a[j])
                                break;
                }
                if(j==i)
                {
                        for(j=i+1,c=1;j<ele;j++)
                               if(a[i] == a[j])
                                c++;
                        if(c>1)
                                printf("the element %d duplicated\n",a[i]);
                }
    }
}