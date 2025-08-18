/*7. Variadic printf() Implementation Challenge

Description
Write a C program to implement a simple printf() function using variadic functions.

Key Concept: Use stdarg.h to accept a format string and variable arguments; print accordingly (simplified version).

Sample Input & Output
Function call:
my_printf(3, 10, 20, 30)
Output:
The values are: 10 20 30

Explanation
The first argument is the count of values to print, followed by those values. All are printed in sequence.

*/

#include <stdio.h>
#include <stdarg.h>

void my_printf(int count, ...) 
{
    va_list args;
    va_start(args, count);
    int num;

    printf("The values are: ");
    for (int i = 0; i < count; i++) 
    {
        int num = va_arg(args, int);
        printf("%d ", num);
    }

    va_end(args);
    printf("\n");
}

int main() 
{
    my_printf(3, 10, 20, 30);

}
