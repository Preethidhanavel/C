/*3.Question: Find maximum and minimum element
Question description: Write a C program to find the largest and smallest element in the array.
Sample data:
Input: 8 3 15 6 2
Expected output:
Maximum = 15
Minimum = 2
*/
#include<stdio.h>
int find_max(int *a,int n)
{
    int i;
    int max=a[0];
    for(i=1;i<n;i++)
    {
        if(max<a[i])
        max=a[i];
    }
    return max;
}
int find_min(int *a,int n)
{

    int i;
    int min=a[0];
    for(i=1;i<n;i++)
    {
        if(min>a[i])
        min=a[i];
    }
    return min;
}
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,sum=0;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("array elements printing\n");
    int x=find_max(a,n);
    int y=find_min(a,n);
    printf("The max:%d  min:%d \n",x,y);
    }