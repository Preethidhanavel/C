/*4.Pointer Comparison
Task: Write code to compare two pointers to elements in an array and print which one points to the element with a smaller index.

Sample data:
1.int arr[] = {11, 22, 33, 44, 55};
2.int *ptr1 = &arr[2];  // points to 33
3.int *ptr2 = &arr[4];  // points to 55
Expected output:
Pointer ptr1 points to an earlier element than ptr2*/

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
    int *p1=&a[3];
    int *p2=&a[2];
    if(p2>p1)
        printf("The pointer p1 points to an earlier element than p2\n");
    else
        printf("The pointer p2 points to an earlier element than p1\n ");
}