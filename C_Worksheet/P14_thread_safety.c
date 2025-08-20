/* Q14. Thread-Safe Singleton in C (No C++)---------------------------------------
Problem Statement:
 Create and return a single shared instance across threads safely*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Simple object
struct Obj {
    int x;
};

// Global static pointer (singleton instance)
static struct Obj* instance = NULL;

// Mutex for thread safety
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Function to get the singleton instance (thread-safe)
struct Obj* get_instance() {
    // First check (no lock) - faster for already created instance
    if (instance == NULL) {
        pthread_mutex_lock(&lock);       // acquire lock

        // Second check inside lock (double-checked locking)
        if (instance == NULL) {
            instance = malloc(sizeof(struct Obj));
            instance->x = 42;            // initialize data
            printf("Instance created by thread\n");
        }

        pthread_mutex_unlock(&lock);     // release lock
    }
    return instance;
}

// Thread function
void* thread_func(void* arg) {
    struct Obj* obj = get_instance();   // all threads call this
    printf("Thread got instance with x = %d, address = %p\n", obj->x, (void*)obj);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create two threads that both try to get the singleton
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
