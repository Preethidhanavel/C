/*3: Pointer Subtraction
Task: Given two pointers pointing to elements of an integer array, find the distance (number of elements) between them.

Sample data:
int arr[] = {2, 4, 6, 8, 10};
int *p1 = &arr[4];  // points to 10
int *p2 = &arr[1];  // points to 4
Expected output:

Distance between pointers is 3*/

#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
int a[n];
int i;
printf("Enter the array elements\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

int *p1=&a[4];
int *p=&a[1];

printf("ouput: distance between pointers is:%d",p1-p);


}