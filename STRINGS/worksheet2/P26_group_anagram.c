//26.Group a list of words so that anagrams are together.
//Input: ["cat", "tac", "act", "dog"]
//Output: ["cat", "tac", "act"], ["dog"]



#include <stdio.h>
#include <string.h>

void sort(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char words[n][50];
    char sorted[n][50];
    int used[n];

    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
        strcpy(sorted[i], words[i]);
        sort(sorted[i]);
        used[i] = 0;
    }

    int group = 1;
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;

        printf("Group %d: %s ", group++, words[i]);
        used[i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (!used[j] && strcmp(sorted[i], sorted[j]) == 0) {
                printf("%s ", words[j]);
                used[j] = 1;
            }
        }
        printf("\n");
    }

    return 0;
}