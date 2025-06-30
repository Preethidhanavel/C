/*43.Find two elements whose sum is closest to zero
Question description:
Write a C program to find two elements whose sum is closest to zero.
Sample data:
Input: 1 60 -10 70 -80 85
Expected output:
Pair whose sum is closest to zero: -80 85*/

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main()
{
int ele;
    printf("Enter the number of elemets:\n");
    scanf("%d",&ele);
    int a[ele];
    int i,j,count;
    printf("Enter the array elements\n");
    for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
    int sum=INT_MAX,p1,p2;
    for(i=0;i<ele;i++){
        for(j=i+1;j<ele;j++)
            if(abs(a[i]+a[j])<abs(sum)){
                sum=a[i]+a[j];
                p1=a[i];
                p2=a[j];    
            }
    }
printf("The sum closest to zero is made by pairs %d %d\n",p1,p2);
}