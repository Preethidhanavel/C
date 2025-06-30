/*47.Find maximum sum of k consecutive elements
Question description:
Write a C program to find maximum sum of k consecutive elements in an array.
Sample data:
Input: 2 3 4 1 5 6 7 k = 3
Expected output:
Maximum sum of 3 consecutive elements: 18*/
#include<stdio.h>

int main()
{
int ele;
    printf("Enter the number of elemets:\n");
    scanf("%d",&ele);
    int a[ele];
    int i,j=0,k=0,l;
    printf("Enter the maximum sum of K consecutive elements\n");
    scanf("%d",&k);
    printf("Enter the array elements\n");
    for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
    int max=0,sum;
    for(i=0;i<ele;i++){
        sum=0;
        for(j=i,l=0;(j<ele)&&(l<k);j++,l++){
            sum=sum+a[j];        
        }
        if(max<sum)
            max=sum;
    }
    printf("The maximum sum is %d\n",max);
}