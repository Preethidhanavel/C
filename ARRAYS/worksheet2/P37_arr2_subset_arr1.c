/*37.Check if array is subset of another
Question description:
Write a C program to check if one array is a subset of another array.
Sample data:
Array 1: 1 2 3 4 5 Array 2: 2 4 5
Expected output:
Array2 is a subset of Array1*/

#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter the number of elemets of array 1 and array 2:\n");
    scanf("%d%d",&m,&n);
    int a[n],b[m];
    int i,j;
     printf("Enter the array1 elements\n");
        for(i=0;i<m;i++)
        scanf("%d",&a[i]);
    printf("Enter the array2 elements\n");
        for(i=0;i<n;i++)
        scanf("%d",&b[i]);

         
    for (int i = 0; i < n; i++) {
        int x = 0;
      
        for (int j = 0; j < m; j++) {
            if (b[i] == a[j]) {
                x = 1;
                break;
            }
        }
        if (!x) {
        printf("The array2 is not a subset\n");
            return 0;
        }
    }
    printf("The array is subset \n");
}