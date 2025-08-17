/* Q23. Stack Canary Detection--------------------------
Problem Statement:
 Detect stack smashing by placing a guard value before return and verifying at function exit*/


#include <stdio.h>
#include <string.h>

// Canary value used to detect stack smashing (corruption)
#define CANARY 0xDEADBEEF 
// function that checks stack integrity
void fun_detect(const char* in) 
{
    unsigned int guard = CANARY;   // place canary on stack
    char buf[8];                   // small buffer

    // Copy input string into buffer safely (limit size)
    strncpy(buf, in, sizeof(buf) - 1);
    buf[7] = '\0';                 // ensure null termination

    // Check if canary was modified (indicates overflow)
    if (guard != CANARY)
        puts("Stack smashed!");    // overflow detected
    else
        puts("Safe.");             // no overflow
}

int main(void) 
{
    fun_detect("hello");   // input fits safely in buffer
    return 0;
}
