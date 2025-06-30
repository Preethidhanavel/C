/*14.Chained Function Pointer Calls
Write several functions that transform an integer (e.g., doubleValue, increment, square).
Log Session an array of function pointers representing a pipeline of operations.
Pass a number through the pipeline by applying each function in sequence, using the array of pointers.
*/



#include <stdio.h>

int doublevalue(int x) 
{ 
    return 2 * x; 
}
int increment(int x) 
{ 
    return x + 1; 
}
int square(int x) 
{ 
    return x * x; 
}

int processpipeline(int x, int (*funcs[])(int), int count) 
{
    for (int i = 0; i < count; i++)
        x = funcs[i](x);
    return x;
}

int main() 
{
    int (*pipeline[])(int) = {doublevalue, increment, square};
    int i;
    printf("input:");
    scanf("%d", &i);
    printf("output: %d\n",processpipeline(i, pipeline, 3));

}
