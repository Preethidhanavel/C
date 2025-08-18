/*4.Menu-driven Calculator Using Function Pointers
Implement mathematical operations (power, modulo, squareRoot) as separate functions.
Store these operation functions in a function pointer array.
Provide a user-interactive menu to select and execute the chosen operation on input values.*/

#include <stdio.h>
#include <math.h>

double power(double a, double b)
{ 
    return pow(a, b); 
}
double modulus(double a, double b) 
{
    int x = (int)a, y = (int)b;
    if (y == 0) 
    {
        printf("Modulo by zero error\n");
        return 0;
    }
    return (double)(x % y);
}
double square(double a, double b) 
{ 
    (void)b; 
    if (a < 0) 
    {
        printf("Square root of negative number error\n");
        return -1;
    }
    return sqrt(a);
}

int main() 
{
    double (*func[3])(double, double);
    func[0]=power;
    func[1]=modulus;
    func[2]=square;

    int choice;

    printf("\nMenu:\n1.Power\n2.Modulo\n3.Square Root\nEnter choice: ");
    scanf("%d", &choice);

    double a, b = 0;
    switch (choice) {
        case 1:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &a, &b);
            printf("Result: %.2lf\n", func[0](a, b));
            break;
        case 2:
            printf("Enter two integers: ");
            scanf("%lf %lf", &a, &b);
            printf("Result: %.0lf\n", func[1](a, b));
            break;
        case 3:
            printf("Enter number: ");
            scanf("%lf", &a);
            printf("Result: %.2lf\n", func[2](a, b));
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

}
