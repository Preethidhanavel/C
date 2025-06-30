//35.arrange characters in a string so that the same characters are at least d distance apart.
//input: "aabbcc", d=2
//output: "abcabc"

#include <stdio.h>
#include <string.h>

int nextChar(int *freq, int *dist) {
    int max = -1;

    for (int i = 0; i < 256; i++) {
        if (dist[i] <= 0 && freq[i] > 0) {
            if (max == -1 || freq[i] > freq[max]) {
                max = i;
            }
        }
    }

    return max; 
}


int rearrange(char *str, char *out, int d) {
    int n = strlen(str);

    int freq[256] = {0};  
    int dist[256] = {0};  

    
    for (int i = 0; i < n; i++) {
        freq[str[i]]++;
    }

    
    for (int i = 0; i < n; i++) {
        int j = nextChar(freq, dist);

        
        if (j == -1)
            return 0;

        out[i] = (char)j;  
        freq[j]--;         
        dist[j] = d;       

        
        for (int k = 0; k < 256; k++) {
            if (dist[k] > 0)
                dist[k]--;
        }
    }

    out[n] = '\0';  
    return 1;       
}


int main() {
    char str[100];
    printf("Enter the string\n");
    scanf("%s",str);
    int d;
    printf("Enter the distance\n");
    scanf("%d",&d);
    int n = strlen(str);
    char out[n + 1];  

    if (rearrange(str, out, d)) {
        printf("Rearranged string: %s\n", out);
    } else {
        printf("Cannot be rearranged\n");
    }

    return 0;
}
