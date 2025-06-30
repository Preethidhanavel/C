/*5.Pointer Arithmetic with Arrays
Goal: Learn how to access array elements using pointer arithmetic.
Activity:
Declare: int arr[5] = {10, 20, 30, 40, 50};
Use int *p = arr;
Use a loop to print all elements via *(p + i).*/

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int a[n],i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int *p=a;
    for(i=0;i<n;i++)
        printf("%d ",*(p+i));
}