/*6.How would you define and use a structure with a flexible array member for dynamic-length data storage*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   //  char data[];
    size_t length;
    char data[];
   
} FlexString;

int main() {
    const char* msg = "Hello, flexible array!";
    size_t len = strlen(msg);
    printf("%ld\n",sizeof(FlexString));
    FlexString* fs = malloc(sizeof(FlexString) + len + 1);
    if (!fs) return 1;

    fs->length = len;
    memcpy(fs->data, msg, len + 1);

    printf("Length: %zu\nData: %s\n", fs->length, fs->data);

    free(fs);
    return 0;
}
