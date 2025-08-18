/* 8.Find the majority element (element that appears more than n/2 times)
Use Moore’s Voting Algorithm to identify the majority element if it exists.

Example: Input: [2, 2, 1, 1, 2, 2, 2]
Output: 2
*/

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
                        if(c>=(ele/2))
                                printf("the element %d occured %d times\n",a[i],c);
                }
    }
}