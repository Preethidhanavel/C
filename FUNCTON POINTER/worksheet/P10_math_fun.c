/*10.Math Function Framework
Write wrapper functions around standard mathematical functions (sin, cos, tan, log) with the same function prototype.
Store pointers to these functions in an array.
Provide an interface for users to select and execute a math function on a given floating-point input.
*/
#include <stdio.h>
#include <math.h>

float my_sin(float x) {
    return sinf(x);
}

float my_cos(float x) {
    return cosf(x);
}

float my_tan(float x) {
    return tanf(x);
}

float my_log(float x) {
    return logf(x);
}

typedef float (*MathFunc)(float);

int main() {
    MathFunc functions[4] = { my_sin, my_cos, my_tan, my_log };
    const char *function_names[4] = { "sin", "cos", "tan", "log" };

    int choice;
    float input, result;

    printf("Select a math function:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i, function_names[i]);
    }

    printf("Enter your choice (0-3): ");
    scanf("%d", &choice);

    if (choice < 0 || choice > 3) {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Enter input value: ");
    scanf("%f", &input);

    result = functions[choice](input);

    printf("Result of %s = %f\n", function_names[choice], input, result);

    return 0;
}
