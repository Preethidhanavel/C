/*12.What are the memory implications of having a union as a member of a structure?
struct Number {
    char type;
    union {
        int i;
        float f;
    } value;
};*/




#include <stdio.h>

struct Number {
    char type;
    union {
        int i;
        float f;
    } value;
};

int main() {
    struct Number n;
    printf("Size: %zu\n", sizeof(n));
    return 0;
}
