/*3.How would you programmatically determine the offset of a structure member? 
Consider why this might be important for low-level operations.*/
#include <stdio.h>
#include <stddef.h>
    struct Info {
    short id;
    float value;
    char tag;
};

int main() {
    printf("Offset of a: %lu bytes\n", offsetof(struct Info, id));
    printf("Offset of b: %lu bytes\n", offsetof(struct Info, value));
    printf("Offset of c: %lu bytes\n", offsetof(struct Info, tag));
    return 0;
}
