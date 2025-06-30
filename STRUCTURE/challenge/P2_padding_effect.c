/*2.If you change the order of members in a structure, how does it affect the overall size due to padding? 
Try predicting the size of these two structures.*/
#include <stdio.h>

struct A {
    char x;
    int y;
    char z;
};

struct B {
    int y;
    char x;
    char z;
};

int main() {
    struct A a;
    struct B b;

    printf("=== Structure A ===\n");
    printf("Size of struct A: %zu bytes\n", sizeof(struct A));
    printf("Address of a.x: %p\n", &a.x);
    printf("Address of a.y: %p\n", &a.y);
    printf("Address of a.z: %p\n", &a.z);

    printf("\n=== Structure B ===\n");
    printf("Size of struct B: %zu bytes\n", sizeof(struct B));
    printf("Address of b.y: %p\n", &b.y);
    printf("Address of b.x: %p\n", &b.x);
    printf("Address of b.z: %p\n", &b.z);

    return 0;
}
