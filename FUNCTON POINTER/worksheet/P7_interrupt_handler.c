/*7.Interrupt Handler Simulation
Log Session several interrupt handler functions (e.g., timerInterrupt, keyboardInterrupt, errorInterrupt).
Map these interrupt handlers using an array of function pointers.
Simulate interrupts by invoking appropriate interrupt handlers using their pointers based
on interrupt numbers entered by the user.*/
#include <stdio.h>

typedef enum {
    TIMER_INTERRUPT,
    KEYBOARD_INTERRUPT,
    ERROR_INTERRUPT,
    NUM_INTERRUPTS
} InterruptType;

void timerInterruptHandler(void);
void keyboardInterruptHandler(void);
void errorInterruptHandler(void);

void (*interruptHandlers[NUM_INTERRUPTS])(void);

void timerInterruptHandler(void) {
    printf("Timer Interrupt handled.\n");
}

void keyboardInterruptHandler(void) {
    printf("Keyboard Interrupt handled.\n");
}

void errorInterruptHandler(void) {
    printf("Error Interrupt handled.\n");
}

void triggerInterrupt(int interruptNumber) {
    if (interruptNumber >= 0 && interruptNumber < NUM_INTERRUPTS && interruptHandlers[interruptNumber] != NULL) {
        interruptHandlers[interruptNumber]();
    } else {
        printf("Invalid interrupt number: %d\n", interruptNumber);
    }
}

int main() 
{
    interruptHandlers[TIMER_INTERRUPT] = timerInterruptHandler;
    interruptHandlers[KEYBOARD_INTERRUPT] = keyboardInterruptHandler;
    interruptHandlers[ERROR_INTERRUPT] = errorInterruptHandler;

    int interruptNumber;
    printf("Enter interrupt number (0: Timer, 1: Keyboard, 2: Error, -1 to exit): ");
    while (scanf("%d", &interruptNumber) == 1 && interruptNumber != -1) {
        triggerInterrupt(interruptNumber);
        printf("Enter interrupt number (0: Timer, 1: Keyboard, 2: Error, -1 to exit): ");
    }

    printf("Exiting interrupt simulation.\n");
    return 0;
}
