/*38.Sort array of 0s, 1s and 2s
Question description:
Write a C program to sort an array consisting of only 0s, 1s, and 2s.
Sample data:
Input: 0 1 2 0 1 2 1 0
Expected output:
Sorted array: 0 0 0 1 1 1 2 2*/
#include<stdio.h>


int main()
{
    int len;
    printf("Enter the number of elements\n");
    scanf("%d",&len);
    int a[len],i;
    printf("Enter the array elements as only 0,1 or 2\n");
    for(i=0;i<len;i++)
    scanf("%d",&a[i]);

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
     for(i=0;i<len;i++)
        printf("%d ",a[i]);

}