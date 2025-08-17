/* Q49. Move All Zeros to End (Stable)----------------------------------
Problem Statement:
 Reorder an array so that all nonzeros retain relative order and all zeros move to the end*/

#include <stdio.h>

// Move all zeros in array 'a' of length 'n' to the end,

void move_zeros(int a[], int n) 
{
    int j = 0;                      // Position to place the next non-zero element

    // Copy all non-zero elements to the front of the array
    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            a[j++] = a[i];

    // Fill the remaining positions with zeros
    while (j < n)
        a[j++] = 0;
}

int main() 
{
    int a[] = {0, 1, 0, 3, 12}, n = 5;

    move_zeros(a, n);               // Move zeros to the end

    // Print the resulting array
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    puts("");

    return 0;
}
