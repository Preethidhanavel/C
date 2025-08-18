/*18.Replace Switch-Case with Function Pointer Table
Simulate a command-based application where each command is represented by a number.
Instead of using a large switch-case block to handle commands, create a function pointer table.
Use the input command number as an index to call the corresponding handler function via the function pointer table.*/




#include <stdio.h>

void hello() 
{ 
    printf("hello\n"); 
}
void good() 
{ 
    printf("goodbye\n"); 
}
void bye() 
{ 
    printf("bye\n"); 
}
void unknown() 
{ 
    printf("unknown\n"); 
}

int main() 
{
    void (*cmds[])() = {hello, good, bye};
    int n = sizeof(cmds) / sizeof(cmds[0]);

    int c;
    printf("cmd (0-2): ");
    scanf("%d", &c);

    if (c >= 0 && c < n)
        cmds[c]();
    else
        unknown();

    
}
