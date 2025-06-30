/*40.Find the maximum difference between two elements such that larger elements appear after the smaller
Question description:
Write a C program to find the maximum difference between two elements in an array such that larger element appears 
after the smaller
sample data
input:2 3 10 6 4 8 1
Expected output:
Maximum difference:8(10-2)*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int ele;
    printf("Enter the number of elemets:\n");
    scanf("%d",&ele);
    int a[ele];
    int i,j=0,k=0;

    printf("Enter the array elements\n");
        for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
        int max=0,s;
     for(i=0;i<ele-2;i++)
     {
        if(a[i+2]>a[i+1])
            s=abs(a[i]-a[i+2]);
            if(s>max){
            max=s;
            k=i;}
     }
  printf("The maximum element is %d(%d,%d)\n",max,a[k],a[k+2]);  
   
}