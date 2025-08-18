/*If you have a union with an int, a float, and a char array, and you store a value in the int member, 
what will happen if you immediately try to read from the float member? Why does this happen?*/

#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data d;

    d.i = 1; 

    printf("int: %d\n", d.i);
    printf("float: %f\n", d.f); 
    return 0;
}
