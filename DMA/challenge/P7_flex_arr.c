/*You have a structure that ends with an array whose size is not fixed. How would you allocate and use this structure in C?*/
#include <stdio.h>
#include <stdlib.h>

struct s {
    int id;
    int length;
    char data[];
};

int main() 
{
    int n = 20;
    struct s *p = (struct s *)malloc(sizeof(struct s) + n);

    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    p->id = 1;
    p->length = n;

    for (int i = 0; i < n; i++) {
        p->data[i] = 'A' + (i % 26);
    }

    printf("Packet ID: %d, Length: %d\nData: ", p->id, p->length);
    for (int i = 0; i < p->length; i++) {
        printf("%c", p->data[i]);
    }
    printf("\n");

    free(p);
    return 0;
}
