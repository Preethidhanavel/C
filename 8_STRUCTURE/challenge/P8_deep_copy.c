/*8.How can you avoid problems with shallow copy when a structure has pointer members, for example, 
when copying one struct to another?*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

Person deepCopyPerson(const Person *original) 
{
    Person copy;
    copy.age = original->age;
    copy.name = malloc(strlen(original->name) + 1);
    if (copy.name) {
        strcpy(copy.name, original->name);
    }
    return copy;
}

int main() 
{
  
    Person p1;
    p1.age = 25;
    p1.name = malloc(20);
    strcpy(p1.name, "Alice");
    Person p2 = deepCopyPerson(&p1);

    strcpy(p1.name, "Bob");

    printf("Original name: %s, age: %d\n", p1.name, p1.age);
    printf("Copied   name: %s, age: %d\n", p2.name, p2.age);
    free(p1.name);
    free(p2.name);

    return 0;
}
