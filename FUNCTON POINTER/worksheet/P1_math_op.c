/*1.Log Session four simple mathematical functions (add, subtract, multiply, divide) that accept two integer arguments 
and return an integer.Use a single function pointer to dynamically select and execute one of these operations 
based on user input.*/
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0)
        return a / b;
    else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

int main() {
    int x, y, choice, result;
    int (*operation)(int, int);

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Choose operation: 1-Add 2-Subtract 3-Multiply 4-Divide\n");
    scanf("%d", &choice);

    if (choice == 1)
        operation = add;
    else if (choice == 2)
        operation = subtract;
    else if (choice == 3)
        operation = multiply;
    else if (choice == 4)
        operation = divide;
    else {
        printf("Invalid choice!\n");
        return 1;
    }

    result = operation(x, y);

    printf("Result: %d\n", result);

    return 0;
}
