/* Q03. Atomic Toggle of a GPIO Bit (MMIO Register)-----------------------------------------------
Problem Statement:
 Safely toggle a specific GPIO bit in a memory-mapped I/O register without 
 race conditions during interrupts*/
#include <stdio.h>
#include <stdint.h>
#include <stdatomic.h>
#include <pthread.h>
#include <unistd.h>

// Simulated MMIO register 
volatile uint32_t GPIO_REG = 0;

// Bit to toggle
#define GPIO_BIT (1u << 3)   // Bit 3

//atomic operation
void gpio_toggle_atomic(void) {
    // XOR bit atomically
    atomic_fetch_xor((_Atomic uint32_t *)&GPIO_REG, GPIO_BIT);
}

// Thread function to simulate concurrent access
void* thread_func(void* arg) {
    for (int i = 0; i < 5; i++) {
        gpio_toggle_atomic();
        printf("Thread %ld toggled: GPIO_REG = 0x%08X\n", (long)arg, GPIO_REG);
        usleep(100000); // 100 ms
    }
    return NULL;
}

int main(void) {
    pthread_t t1, t2;

    printf("Initial GPIO_REG = 0x%08X\n", GPIO_REG);

    // Create two threads simulating concurrent toggles
    pthread_create(&t1, NULL, thread_func, (void*)1);
    pthread_create(&t2, NULL, thread_func, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final GPIO_REG = 0x%08X\n", GPIO_REG);
    return 0;
}

