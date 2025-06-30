/*2.Size of Union
Write a program to declare a union containing an int, a double, and a char.
Print the size of this union using sizeof. Compare the result with the size of a structure having the same members.*/
#include <stdio.h>

union MyUnion {
    int i;
    double d;
    char c;
    int *p;
    union Myunion*p1;
};

struct MyStruct {
    int i;
    double d;
    char c;
   int *p;
};

int main() {
    printf("Size of union: %zu bytes\n", sizeof(union MyUnion));
    printf("Size of struct: %zu bytes\n", sizeof(struct MyStruct));
    return 0;
}
