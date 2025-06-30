/*29. Check if array is palindrome
Question description:
Write a C program to check whether an array is palindrome (reads the same forward and backward).
Sample data:
Input: 1 2 3 2 1
Expected output:
The array is a palindrome.*/
#include<stdio.h>
int main()
        {
        int n;
        printf("Enter the number of elemets:\n");
        scanf("%d",&n);
        int a[n];
        int i,j;
        printf("Enter the array elements\n");
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);

        for(i=0,j=n-1;i<j;i++,j--)
                {
                        if(a[i] != a[j])
                        break;
                }
                if(i<j)
                printf("not palindrome format...\n");
                else
                printf("palindrome format...\n");
}
