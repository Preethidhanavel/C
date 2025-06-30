/*Pointer to a Union
Write a program that defines a union called Sample with an int and a float.
Declare a pointer to the union. Assign values using the pointer and print the results.*/

#include <stdio.h>

union Sample 
{
    int i;
    float f;
};

int main() 
{
    union Sample s;
    union Sample *ptr = &s;

    ptr->i = 42;
    printf("Integer value: %d\n", ptr->i);

    ptr->f = 3.14f;
    printf("Float value: %.2f\n", ptr->f);

}
