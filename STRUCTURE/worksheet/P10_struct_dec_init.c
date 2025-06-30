/*10.Structure Declaration and Initialization
Goal
Understand the proper way to declare and initialize structures using multiple techniques and best practices.

Activity
Declare structure variables globally, locally, and statically.
Use designated initializers for clarity.
Use typedef to create aliases for complex structures.
Discuss structure initialization in embedded register mapping.
Tip: Static initialization is preferred for compile-time register definitions.*/
#include <stdio.h>

typedef struct {
    char name[30];
    int age;
} Person;

Person globalPerson = {
    .name = "Alice",
    .age = 25
};

static Person staticPerson = {
    .name = "Bob",
    .age = 30
};

typedef struct {
    volatile unsigned int MODER;
    volatile unsigned int OTYPER;
    volatile unsigned int OSPEEDR;
    volatile unsigned int PUPDR;
} GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef *) 0x40021000)

void configureGPIO() {
    GPIOA->MODER = 0xA8000000;
    GPIOA->OTYPER = 0x00000001;
    GPIOA->OSPEEDR = 0x00000003;
    GPIOA->PUPDR = 0x00000000;
}

int main() {
    Person localPerson = {
        .name = "Carol",
        .age = 35
    };

    Person people[] = {
        { .name = "David", .age = 40 },
        { .name = "Eva", .age = 22 }
    };

    printf("Global Person: %s, %d\n", globalPerson.name, globalPerson.age);
    printf("Static Person: %s, %d\n", staticPerson.name, staticPerson.age);
    printf("Local Person: %s, %d\n", localPerson.name, localPerson.age);

    for (int i = 0; i < 2; i++) {
        printf("Person[%d]: %s, %d\n", i, people[i].name, people[i].age);
    }

    configureGPIO();

    return 0;
}
