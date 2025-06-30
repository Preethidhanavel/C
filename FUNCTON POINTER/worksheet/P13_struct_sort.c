/*13.Passing Function Pointers to Standard Algorithms
Define a structure representing a record (e.g., struct Person { char name[30]; int age; }).
Implement multiple comparison functions for sorting (e.g., by name, by age).
Use the C standard library function qsort, passing these comparison functions as function 
pointers to sort an array of records in different ways.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
} Person;

int compareByName(const void *a, const void *b) 
{
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return strcmp(p1->name, p2->name);
}

int compareByAge(const void *a, const void *b) 
{
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return p1->age - p2->age;
}

void printPeople(Person people[], int size) 
{
    for (int i = 0; i < size; i++) {
        printf("%s, %d\n", people[i].name, people[i].age);
    }
}

int main() 
{
    Person people[] = { {"Alice", 30},{"Bob", 25},{"Charlie", 35},{"Eve", 22}};
    int size = sizeof(people) / sizeof(people[0]);
    int choice;

    printf("Choose sorting criteria:\n");
    printf("1. By Name\n");
    printf("2. By Age\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        qsort(people, size, sizeof(Person), compareByName);
    } else if (choice == 2) {
        qsort(people, size, sizeof(Person), compareByAge);
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    printf("\nSorted List:\n");
    printPeople(people, size);

    return 0;
}
