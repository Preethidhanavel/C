/*6.Event Handling System
Define events such as buttonPressEvent, sensorTriggerEvent.
Implement handler functions for these events.
Log Session an array of function pointers mapping each event to its corresponding handler function.
Simulate event triggers, calling the appropriate handler through function pointers.*/
#include <stdio.h>

typedef enum {
    BUTTON_PRESS_EVENT,
    SENSOR_TRIGGER_EVENT,
    NUM_EVENTS
} EventType;

void buttonPressHandler(void);
void sensorTriggerHandler(void);

void (*eventHandlers[NUM_EVENTS])(void);

void buttonPressHandler(void) 
{
    printf("Button Press Event handled.\n");
}

void sensorTriggerHandler(void) 
{
    printf("Sensor Trigger Event handled.\n");
}

void triggerEvent(EventType event) 
{
    if (event < NUM_EVENTS && eventHandlers[event] != NULL) 
    {
        eventHandlers[event]();
    } else 
    {
        printf("No handler registered for event %d\n", event);
    }
}

int main() 
{
    eventHandlers[BUTTON_PRESS_EVENT] = buttonPressHandler;
    eventHandlers[SENSOR_TRIGGER_EVENT] = sensorTriggerHandler;

    printf("Simulating events...\n");
    triggerEvent(BUTTON_PRESS_EVENT);
    triggerEvent(SENSOR_TRIGGER_EVENT);
    triggerEvent(999);

    return 0;
}
