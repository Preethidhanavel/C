/*6. Variadic Average Function Challenge

Description
Write a C program to find the average of a variable number of doubles passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to process double arguments and calculate their mean.

Sample Input & Output
Function call:
average(4, 10.5, 30.2, 40.1, 20.6)
Output:
The average is: 25.350000

Explanation
The first argument is the count of double values, followed by the values. The average is computed and returned.

*/


#include <stdio.h>
#include <stdarg.h>

double average(int count, ...) 
{
    double num,sum = 0;
    va_list args;

    va_start(args, count);

    for (int i = 0; i < count; i++) 
    {
        num = va_arg(args, double);
        sum += num;
    }

    va_end(args);

    return sum/count;
}

int main() 
{
    double result = average(4, 10.5, 30.2, 40.1, 20.6);
    printf("The average is: %f\n", result);
    
}
