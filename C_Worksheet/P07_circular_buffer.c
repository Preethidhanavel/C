/* Q07. Circular Buffer for Byte Storage------------------------------------
Problem Statement:
 Implement a ring buffer to store bytes with head/tail indices and overwrite protection.*/
#include <stdio.h>

#define SIZE 5                // buffer size
unsigned char buffer[SIZE];   // circular buffer storage
int head = 0, tail = 0;       // head = write index, tail = read index

// Function to write one byte into buffer
int write_byte(unsigned char b) 
{
    int next = (head + 1) % SIZE;  // calculate next position (wrap around)
    if (next == tail) return -1;   // buffer full
    buffer[head] = b;              // store byte
    head = next;                   // move head forward
    return 0;                      // success
}

// Function to read one byte from buffer
int read_byte(unsigned char *b) 
{
    if (head == tail) return -1;   // buffer empty
    *b = buffer[tail];             // read byte
    tail = (tail + 1) % SIZE;      // move tail forward
    return 0;                      // success
}

int main() 
{
    // Write two bytes into buffer
    write_byte('A');
    write_byte('B');

    unsigned char c;

    // Read first byte
    if (read_byte(&c) == 0)
        printf("Read: %c\n", c);

    // Read second byte
    if (read_byte(&c) == 0)
        printf("Read: %c\n", c);

    return 0;
}

