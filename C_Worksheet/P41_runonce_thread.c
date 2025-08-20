/* Q41. Run Once (Thread-Safe)--------------------------
Problem Statement:
 Ensure a function body executes only once across threads*/

#include <stdio.h>
#include <pthread.h>

// pthread_once control variable, initialized to run once
pthread_once_t once = PTHREAD_ONCE_INIT;

int shared = 0; // Shared variable to be initialized once

// Initialization function to be called exactly once
void init(void) 
{
    puts("init called");  // Print when initialization happens
    shared = 42;          // Initialize shared data
}

// Worker thread function
void* worker(void* arg) 
{
    // Ensure 'init' is called only once, no matter how many threads call this
    pthread_once(&once, init);

    // After initialization, print the shared value
    printf("shared=%d\n", shared);
    return NULL;
}

int main() 
{
    pthread_t t1, t2;

    // Create two threads that both call worker
    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
