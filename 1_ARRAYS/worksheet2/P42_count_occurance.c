/*42.Count occurrences of a number
Question description:
Write a C program to count how many times a specific number appears in an array.
Sample data:
Input array: 1 2 3 2 2 5 Number to count: 2
Expected output:
Number 2 occurs 3 times*/
#include<stdio.h>
int main()
{
int ele;
    printf("Enter the number of elemets:\n");
    scanf("%d",&ele);
    int arr[ele];
    int i,j,count=0;
    printf("Enter the array elements\n");
    for(i=0;i<ele;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to count\n");
    int n;
    scanf("%d",&n);
    for(i=0;i<ele;i++){
        if(arr[i]==n)
          count++;
    }
  printf("The element occured %d times\n",count);
}
