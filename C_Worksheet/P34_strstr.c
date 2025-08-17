/* Q34. strstr Without Library--------------------------
Problem Statement:
 Find first occurrence of needle in haystack and return its index (or -1)*/


#include <stdio.h>

// Custom implementation of strstr
int my_strstr(const char* h, const char* n) 
{
    if (!*n) 
        return 0; // If needle is empty string, return 0

    // Loop through each character of the haystack
    for (int i = 0; h[i]; i++) 
    {
        int j = 0;

        // Check if the substring starting at h[i] matches the needle
        while (n[j] && h[i + j] == n[j]) 
            j++;

        // If we reached the end of needle (match found), return starting index i
        if (!n[j]) 
            return i;
    }

    // If no match found, return -1
    return -1;
}

int main() 
{
    printf("%d\n", my_strstr("embedded c rocks", "c "));
    return 0;
}
