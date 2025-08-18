/*9.Given an array, find the XOR of all elements excluding a particular specified element.*/
#include<stdio.h>
int compute_xor(int *a,int n)
{
    int i,res=0;
    for(i=0;i<n;i++)
        res^=a[i];
        return res;
      
}
int main()
{
    int n,m;
     printf("Enter the number of elements\n");
    scanf("%d",&n);
    int i,a[n];
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("enter the number to be excluded\n");
    scanf("%d",&m);
  
    int n1=  compute_xor(a,n);
    printf("The xor of all number in range is %d\n",n1^m);
}