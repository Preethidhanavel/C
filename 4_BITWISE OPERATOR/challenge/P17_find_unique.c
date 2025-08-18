/*17.In an array where every element appears twice except one, find that single unique number.*/
#include <stdio.h>

int findUnique(int *arr, int n)
 {
    int result = 0;    
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        int x = (1 << i); 

        for (int j = 0; j < n; j++) {
            if (arr[j] & x)
                sum++;
        }

        if (sum % 3)
            result |= x;
    }
    return result;
}

int main() {

    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int arr[n];
    int i,j;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int unique = findUnique(arr, n);
    printf("The unique element is: %d\n", unique);

    return 0;
}
