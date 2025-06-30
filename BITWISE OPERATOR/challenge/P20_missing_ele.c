/*20.Given an array of size n-1 containing numbers from 1 to n with one missing, find the missing number using XOR.*/

#include <stdio.h>

int find(int a[], int n) {
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
        x ^= i;
    for (int i = 0; i < n - 1; i++)
        y ^= a[i];
    return x ^ y;
}

int main() {
    int n;
    printf("enter no of ele ");
    scanf("%d", &n);

    int a[n - 1];
    printf("enter ele");
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &a[i]);

    printf("Missing number: %d\n", find(a, n));
    return 0;
}
