/*15.Multi-dimensional Function Pointer Array
Define arithmetic functions for both int and float types (e.g., intAdd, floatAdd).
Organize the function pointers in a two-dimensional array:
First dimension: operation type (arithmetic, bitwise)
Second dimension: data type (int, float)
Demonstrate calling the correct function based on selected type and operation.
*/
#include <stdio.h>

typedef int (*IntFunc)(int, int);
typedef float (*FloatFunc)(float, float);

int intAdd(int a, int b) 
{ 
    return a + b; 
}
int intSubtract(int a, int b) 
{
     return a - b; 
}

float floatAdd(float a, float b) 
{ 
    return a + b; 
}
float floatSubtract(float a, float b) 
{ 
    return a - b; 
}

int main() 
{
    IntFunc intFuncs[2] = { intAdd, intSubtract };
    FloatFunc floatFuncs[2] = { floatAdd, floatSubtract };

    int dataType, operation;
    printf("Select data type (0 = int, 1 = float): ");
    scanf("%d", &dataType);

    printf("Select operation (0 = add, 1 = subtract): ");
    scanf("%d", &operation);

    if (dataType == 0) {
        int x, y;
        printf("Enter two integers: ");
        scanf("%d %d", &x, &y);
        int result = intFuncs[operation](x, y);
        printf("Result: %d\n", result);
    } 
    else if (dataType == 1) {
        float x, y;
        printf("Enter two floats: ");
        scanf("%f %f", &x, &y);
        float result = floatFuncs[operation](x, y);
        printf("Result: %.4f\n", result);
    } 
    else {
        printf("Invalid data type.\n");
    }

    return 0;
}


