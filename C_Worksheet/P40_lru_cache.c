/*Q40. Simulate LRU Cache (No Libraries)-------------------------------------
Problem Statement:
 Maintain a small cache (capacity C) where accesses move items to front; 
 evict least recently used at tail.*/

#include <stdio.h>

#define CAP 4                 // Cache capacity

int cache[CAP];               // Cache storage (most recent at index 0)
int size = 0;                 // Current number of elements in cache

// Find the index of key k in cache, or -1 if not found
int find(int k) 
{
    for (int i = 0; i < size; i++)
        if (cache[i] == k) return i;
    return -1;
}

// Access a key k: update cache according to LRU policy
void access_key(int k) 
{
    int idx = find(k);

    if (idx == -1) 
    { // Cache miss
        if (size < CAP) size++;           // Increase size if not full
        // Shift elements right to make space at front
        for (int i = size - 1; i > 0; i--)
            cache[i] = cache[i - 1];
        cache[0] = k;                     // Insert new key at front (MRU)
    } 
    else 
    { // Cache hit
        int v = cache[idx];               // Store the found key
        // Shift elements from idx down to 1 to right by one
        for (int i = idx; i > 0; i--)
            cache[i] = cache[i - 1];
        cache[0] = v;                     // Move hit key to front (MRU)
    }
}

// Print current cache content (MRU to LRU)
void show(void) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", cache[i]);
    puts("");
}

int main() 
{
    access_key(1); access_key(2); access_key(3); show();  // Cache: 3 2 1
    access_key(2); show();                                // 2 becomes MRU: 2 3 1
    access_key(4); access_key(5); show();                 // Add 4 and 5, evict LRU: 5 4 2 3
    return 0;
}
