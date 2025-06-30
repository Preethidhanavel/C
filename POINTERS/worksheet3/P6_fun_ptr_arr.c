/*6.Function Pointer Arrays for Command Execution
Goal: Log Session an embedded command interface using an array of function pointers.
Activity:
Declare three functions representing device operations:
void init(void);
void start(void);
void stop(void);
Log Session an array of function pointers referencing these functions:
void (*cmd_table[])(void) = {init, start, stop};
Use an index or enum value to invoke the appropriate function via the array.*/

#include <stdio.h>

void init(void) 
{
    printf("Device Initialized\n");
}

void start(void) 
{
    printf("Device Started\n");
}

void stop(void) 
{
    printf("Device Stopped\n");
}

typedef enum {
    CMD_INIT = 0,
    CMD_START,
    CMD_STOP
} Command;

int main() 
{
    void (*cmd_table[])(void) = {init, start, stop};
    int user_input = CMD_START;
    cmd_table[user_input]();
    return 0;
}
