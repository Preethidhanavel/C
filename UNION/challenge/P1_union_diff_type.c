/*You are building a program to handle messages that can have different types of data, like numbers (int or float) or short text. 
How can a union help you use less memory for this? 
What do you need to be careful about when using the union?*/
#include <stdio.h>
#include <string.h>

enum Type {
    INT,
    TEXT
};

union Message {
    int intValue;
    char text[16];
};

struct MessageWrapper {
    enum Type type;
    union Message data;
};

int main() {
    struct MessageWrapper m;

    m.type = INT;
    m.data.intValue = 123;

    if (m.type == INT) {
        printf("Integer: %d\n", m.data.intValue);
    }

    m.type = TEXT;
    strcpy(m.data.text, "Hi!");

    if (m.type == TEXT) {
        printf("Text: %s\n", m.data.text);
    }

    return 0;
}
