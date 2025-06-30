/*17.Array of Function Pointers in a Structure
Define a structure (e.g., Calculator) that contains an array of function pointers for operations (add, subtract, multiply).
Instantiate the structure and use it to call the various operations on input values, demonstrating how the structure 
can perform different calculations.*/
#include <stdio.h>

typedef int (*Operation)(int, int);

typedef struct {
    Operation operations[3];
} Calculator;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() 
{
    Calculator calc;
    calc.operations[0] = add;
    calc.operations[1] = subtract;
    calc.operations[2] = multiply;

    int a, b, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\nChoose operation:\n");
    printf("0. Add\n");
    printf("1. Subtract\n");
    printf("2. Multiply\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < 3) {
        int result = calc.operations[choice](a, b);
        printf("Result: %d\n", result);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
