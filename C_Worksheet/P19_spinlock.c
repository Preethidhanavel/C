/* Q19. Spinlock via Test-and-Set-----------------------------
Problem Statement:
 Implement a simple busy-wait mutex using a shared flag and test-and-set primitive*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Shared spinlock variable
volatile int lock = 0;

// Acquire spinlock using atomic test-and-set
void acquire_lock(volatile int *lock) 
{
    while (__sync_lock_test_and_set(lock, 1));
    
}

// Release spinlock
void release_lock(volatile int *lock) 
{
    __sync_lock_release(lock); // sets lock = 0 atomically
}

// Shared counter
int counter = 0;

// Worker thread function
void* worker(void *arg) 
{
    for (int i = 0; i < 5; i++) 
    {
        acquire_lock(&lock);            // enter critical section
        int tmp = counter;
        usleep(1000);                   // simulate work
        counter = tmp + 1;              // update shared variable
        printf("Thread %ld incremented counter to %d\n", (long)arg, counter);
        release_lock(&lock);            // exit critical section
    }
    return NULL;
}

int main() 
{
    pthread_t t1, t2;

    // Create two threads
    pthread_create(&t1, NULL, worker, (void*)1);
    pthread_create(&t2, NULL, worker, (void*)2);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value = %d\n", counter);
    return 0;
}
