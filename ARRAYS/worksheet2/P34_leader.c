/*34.Find leader elements in array
Question description:
Write a C program to find all leader elements in the array (elements greater than all elements to their right).
Sample data:
Input: 16 17 4 3 5 2
Expected output:
Leader elements: 17 5 2*/

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
                for (int i = 0; i < n; i++) {
                        int j;
                        for (j = i + 1; j < n; j++) {
                            if (a[i] < a[j])
                                break;
                        }
                        if (j == n) {
                            printf("%d ", a[i]);
                        }
                    }
                    printf("\n");
}