/*Description
Write a C program to compute the sum of any number of integers passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h macros (va_list, va_start, va_arg, va_end) to access a variable number of arguments.

Sample Input & Output
Function calls:
sum(3, 1, 2, 3) → Output: 6
sum(5, 1, 2, 3, 4, 5) → Output: 15
sum(3, -1, -2, -3) → Output: -6

Explanation
The first argument is the count of values, followed by that many integers. The function returns their sum.*/

#include<stdio.h>
#include<stdarg.h>

int sum(int count,...)
{
    va_list args;
    va_start(args,count);
    
    int total=0;
    for(int i=0;i<count;i++)
    {
        total+=va_arg(args,int);
    }
    va_end(args);
    return total;
}





int main()
{
    printf("sum=%d\n",sum(3, 1, 2, 3));
    printf("sum=%d\n",sum(5, 1, 2, 3, 4, 5));
    printf("sum=%d\n",sum(3, -1, -2, -3));
}