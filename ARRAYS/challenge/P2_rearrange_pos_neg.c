/*2.Rearrange array elements so that positive and negative numbers are placed alternatively
Without changing the relative order of positive and negative numbers, rearrange them alternately. 
Extra space should be avoided if possible.
Example: Input: [1, 2, -3, -1, -2, 3]
Output: [1, -3, 2, -1, 3, -2]*/

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
    int c[50],d[50];
        for(i=0;i<ele;i++)
        {
            if(a[i]<0)
            c[j++]=a[i];
        }
        for(i=0;i<ele;i++)
            if(a[i]>=0)
                d[k++]=a[i];
        for(i=0;i<ele;i++){
            if(i<k)
                printf("%d ",d[i]);
            if(i<j)
                printf("%d ",c[i]);
        }
}