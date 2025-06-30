/*8.Generic Find Function
Implement a generic function find that takes an integer array, its size, and a function pointer as a condition.
Log Session condition functions (e.g., isEven, isPositive, isPrime).
Use find to identify and print the first element matching the provided condition.
*/
#include <stdio.h>

int isEven(int x) {
    return x % 2 == 0;
}

int isPositive(int x) {
    return x > 0;
}

int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int find(int arr[], int size, int (*condition)(int)) {
    for (int i = 0; i < size; i++) {
        if (condition(arr[i])) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int arr[] = { -3, -5, -2, 4, 7, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int result;

    result = find(arr, size, isEven);
    printf("First even: %d\n", result);

    result = find(arr, size, isPositive);
    printf("First positive: %d\n", result);

    result = find(arr, size, isPrime);
    printf("First prime: %d\n", result);

    return 0;
}
