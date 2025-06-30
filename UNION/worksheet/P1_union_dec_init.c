/*1.Union Declaration and Initialization
Declare a union named Data with an int, a float, and a char array of size 20.
Write a program to initialize and print each member, one after the other. Observe and explain the output.*/
#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;
    
    data.i = 10;
    printf("After setting int: i = %d\n", data.i);

    data.f = 220.5;
    printf("After setting float: f = %.2f\n", data.f);

    strcpy(data.str, "Hello, Union!");
    printf("After setting string: str = %s\n", data.str);

    printf("\nAfter setting string, printing all members:\n");
    printf("i = %d\n", data.i);
    printf("f = %.2f\n", data.f);
    printf("str = %s\n", data.str);

    return 0;
}
