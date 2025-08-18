/*11.How can you initialize every member of a structure—including nested structures and arrays—at the time of declaration?*/
#include <stdio.h>

struct Inner {
    int x;
    float y;
};

struct Outer {
    int id;
    struct Inner inner;
    char name[10];
    int scores[3];
};

int main() {
    struct Outer obj = {101,{5, 3.14},"Alice",{90, 85, 88}};

    printf("id = %d\n", obj.id);
    printf("inner.x = %d, inner.y = %.2f\n", obj.inner.x, obj.inner.y);
    printf("name = %s\n", obj.name);
    printf("scores = %d, %d, %d\n", obj.scores[0], obj.scores[1], obj.scores[2]);

    return 0;
}
