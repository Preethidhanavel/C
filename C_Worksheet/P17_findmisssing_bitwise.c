/* Q17. Find Missing Number (0..n) via XOR--------------------------------------
Problem Statement:
 Given an array of n elements of 0..n with one missing, find the missing value 
 in O(n) time and O(1) extra space*/

#include <stdio.h>

// Function to find missing number in array

int find_missing(int a[], int n) 
{
    int x1 = 0, x2 = 0;

    // XOR of all numbers from 0 to n
    for (int i = 0; i <= n; i++) 
        x1 ^= i;

    // XOR of all elements in the array
    for (int i = 0; i < n; i++)  
        x2 ^= a[i];

    // XOR of (all numbers) ^ (array numbers) = missing number
    return x1 ^ x2;
}

int main() 
{
    int a[] = {0, 1, 2, 4, 5}; // here, number 3 is missing
    int n = 5; // means numbers are from 0..5 (total 6 numbers, one missing)

    printf("Missing = %d\n", find_missing(a, n));
    return 0;
}
