/*21.How would you mimic inheritance in C using structures to allow a form of code reuse?
struct Animal {
    char name[10];
};
struct Dog {
    struct Animal base;
    int barkVolume;
};*/



#include <stdio.h>
#include <string.h>

struct animal 
{
    char name[10];
};

void print_animal(struct animal *a) 
{
    printf("Name: %s\n", a->name);
}

struct dog 
{
    struct animal base;
    int bark_volume;
};

void print_dog(struct dog *d) 
{
    print_animal(&d->base);
    printf("Bark Volume: %d\n", d->bark_volume);
}

int main() 
{
    struct dog d;
    strcpy(d.base.name, "Buddy");
    d.bark_volume = 7;
    print_dog(&d);
}
