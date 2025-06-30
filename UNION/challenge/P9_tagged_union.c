//If you have an array of unions, and you store different types in each element (like int, float, or string), 
//what problems can you run into if you try to read all values as the same type later? How can you avoid or check for this problem?

#include <stdio.h>
#include <string.h>

typedef enum {
    INT,
    FLOAT,
    STRING
} TypeTag;

union Value {
    int i;
    float f;
    char str[20];
};

struct TaggedValue {
    TypeTag type;
    union Value value;
};

int main() {
    struct TaggedValue array[3];

    array[0].type = INT;
    array[0].value.i = 42;

    array[1].type = FLOAT;
    array[1].value.f = 3.14;

    array[2].type = STRING;
    strcpy(array[2].value.str, "Hello");

    for (int i = 0; i < 3; i++) {
        switch (array[i].type) {
            case INT:
                printf("INT: %d\n", array[i].value.i);
                break;
            case FLOAT:
                printf("FLOAT: %f\n", array[i].value.f);
                break;
            case STRING:
                printf("STRING: %s\n", array[i].value.str);
                break;
        }
    }

    return 0;
}
