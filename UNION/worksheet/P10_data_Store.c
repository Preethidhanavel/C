/*Use Case – Variant Data Storage
Design a simple employee record system using a structure with a union that can store either salary (float) or 
hourly wage (float), depending on employee type.
Add code to input and print details for a list of employees.*/
#include <stdio.h>

#define N 5

struct E {
    char n[50];
    char t;
    union {
        float s;
        float h;
    } p;
};

int main() {
    struct E e[N];
    int x, i;

    printf("Enter number of employees (max %d): ", N);
    scanf("%d", &x);

    for (i = 0; i < x; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", e[i].n);

        printf("Type (S/H): ");
        scanf(" %c", &e[i].t);

        if (e[i].t == 'S' || e[i].t == 's') {
            printf("Salary: ");
            scanf("%f", &e[i].p.s);
        } else if (e[i].t == 'H' || e[i].t == 'h') {
            printf("Hourly Wage: ");
            scanf("%f", &e[i].p.h);
        } else {
            e[i].t = 'H';
            e[i].p.h = 0.0f;
        }
    }

    printf("\nDetails:\n");
    for (i = 0; i < x; i++) {
        printf("\nName: %s\n", e[i].n);
        if (e[i].t == 'S' || e[i].t == 's') {
            printf("Type: Salaried\n");
            printf("Salary: %.2f\n", e[i].p.s);
        } else {
            printf("Type: Hourly\n");
            printf("Hourly Wage: %.2f\n", e[i].p.h);
        }
    }

    return 0;
}
