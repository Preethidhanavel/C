/*5.State Machine Implementation
Implement a basic state machine (initState, runState, stopState, errorState) with each state represented by a separate function.
Use function pointers to transition between states based on user input or internal conditions.
Demonstrate state transitions clearly in your program’s output.
*/
#include <stdio.h>
#include <stdlib.h>

typedef void (*StateFunc)();

void initState();
void runState();
void stopState();
void errorState();

StateFunc currentState;

void initState() {
    printf("State: INIT\n");
    printf("Enter 1 to RUN, 4 for ERROR: ");
    int input;
    scanf("%d", &input);
    if (input == 1)
        currentState = runState;
    else if (input == 4)
        currentState = errorState;
    else
        currentState = initState;
}

void runState() {
    printf("State: RUNNING\n");
    printf("Enter 2 to STOP, 4 for ERROR: ");
    int input;
    scanf("%d", &input);
    if (input == 2)
        currentState = stopState;
    else if (input == 4)
        currentState = errorState;
    else
        currentState = runState;
}

void stopState() {
    printf("State: STOPPED\n");
    printf("Enter 1 to RESTART, 4 for ERROR: ");
    int input;
    scanf("%d", &input);
    if (input == 1)
        currentState = runState;
    else if (input == 4)
        currentState = errorState;
    else
        currentState = stopState;
}

void errorState() {
    printf("State: ERROR\n");
    printf("System halted. Enter 0 to RESET: ");
    int input;
    scanf("%d", &input);
    if (input == 0)
        currentState = initState;
    else
        currentState = errorState;
}

int main() {
    currentState = initState;
    while (1) {
        currentState();
    }
    return 0;
}
