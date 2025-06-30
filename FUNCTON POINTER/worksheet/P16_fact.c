/*16.Recursive Function Pointer
Implement a recursive function (such as factorial or fibonacci) 
using a function pointer variable instead of directly calling the function by name.
Show that the recursion works correctly using only the pointer.*/
#include <stdio.h>

int factorial(int n);

int (*funcPtr)(int) = factorial;

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * funcPtr(n - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = funcPtr(num);
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}
