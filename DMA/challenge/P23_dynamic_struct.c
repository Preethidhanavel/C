/*Suppose you have a struct that points to other dynamically allocated structs. 
Write a function that frees all memory for these nested structs.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address {
    char *city;
    char *street;
};

struct Person {
    char *name;
    struct Address *addr;
};

struct Person* createPerson(const char *name, const char *city, const char *street) 
{
    struct Person *p = malloc(sizeof(struct Person));
    if (!p) return NULL;

    p->name = malloc(strlen(name) + 1);
    if (p->name) 
      strcpy(p->name, name);

    p->addr = malloc(sizeof(struct Address));
    if (!p->addr) 
    {
        free(p->name);
        free(p);
        return NULL;
    }

    p->addr->city = malloc(strlen(city) + 1);
    if (p->addr->city) 
     strcpy(p->addr->city, city);

    p->addr->street = malloc(strlen(street) + 1);
    if (p->addr->street) 
     strcpy(p->addr->street, street);

    return p;
}

void printPerson(const struct Person *p) 
{
    if (p) 
    {
        printf("Name: %s\n", p->name);
        if (p->addr) 
        {
            printf("City: %s\n", p->addr->city);
            printf("Street: %s\n", p->addr->street);
        }
    }
}

void freePerson(struct Person *p) 
{
    if (p == NULL) return;

    if (p->name) free(p->name);
    if (p->addr) 
    {
        if (p->addr->city) free(p->addr->city);
        if (p->addr->street) free(p->addr->street);
        free(p->addr);
    }
    free(p);
}

int main() 
{
    struct Person *p = createPerson("Alice", "Chennai", "MG Road");

    if (p) 
    {
        printPerson(p);
        freePerson(p);
    }

    
}
