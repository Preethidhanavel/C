/*19.How does sizeof behave with structures containing bit-fields or a flexible array member?*/
#include <stdio.h>

struct Flex {
    int a : 5;
    char data[];
};

int main() 
{
    printf("Size of struct Flex: %zu\n", sizeof(struct Flex));
    return 0;
}
