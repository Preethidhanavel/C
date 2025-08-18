/*13.How would you compare two structures for equality when they include pointer members?*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Person {
    char *name;
    int age;
};


struct Person create_person(const char *name, int age) {
    struct Person p;
    p.age = age;
    p.name = malloc(strlen(name) + 1);
    if (p.name != NULL) {
        strcpy(p.name, name);
    }
    return p;
}


void free_person(struct Person *p) {
    if (p->name != NULL) {
        free(p->name);
        p->name = NULL;
    }
}

int are_equal(const struct Person *a, const struct Person *b) {
    if (a->age != b->age) {
        return 0;
    }

    if (a->name == NULL && b->name == NULL) {
        return 1;
    }

    if (a->name == NULL || b->name == NULL) {
        return 0;
    }

    return strcmp(a->name, b->name) == 0;
}


int main() {
    struct Person p1 = create_person("Alice", 30);
    struct Person p2 = create_person("Alice", 30);
    struct Person p3 = create_person("Bob", 25);

    if (are_equal(&p1, &p2)) {
        printf("p1 and p2 are equal\n");
    } else {
        printf("p1 and p2 are NOT equal\n");
    }

    if (are_equal(&p1, &p3)) {
        printf("p1 and p3 are equal\n");
    } else {
        printf("p1 and p3 are NOT equal\n");
    }

    free_person(&p1);
    free_person(&p2);
    free_person(&p3);

    return 0;
}
