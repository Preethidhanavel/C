/*8.Pointer Arithmetic and Array Bounds
Task: Write code that attempts to access memory outside an array using pointer arithmetic and explain why this is unsafe.

Sample data:
1.int arr[] = {10, 20, 30};
2.int *ptr = arr + 5; // Out of bounds
Expected output:

Undefined behavior - accessing memory outside the array may cause crash or unexpected results*/

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);
    int a[n],i;
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int *p=a;
    while(1)
    {   
            if(p>a+(n-1))
        {
            printf("\narray size exceeded\n");
            return 0;
        }
        printf("%d ",*p);
        p++;
    }
}