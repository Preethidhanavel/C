/*3.Write a function that copies only the unique lines from a source text file to a destination file, preserving order. 
For example, if a line appears more than once, only its first occurrence is copied.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000

int is_unique(char *line, char **seen_lines, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(line, seen_lines[i]) == 0)
            return 0;
    }
    return 1;
}

int main() {
    char src_filename[100], dest_filename[100];
    FILE *src, *dest;

    printf("Enter source file name: ");
    scanf("%s", src_filename);
    printf("Enter destination file name: ");
    scanf("%s", dest_filename);

    src = fopen(src_filename, "r");
    dest = fopen(dest_filename, "w");

    if (!src || !dest) {
        printf("Error opening file(s).\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    size_t read;

    char *seen[MAX_LINES];
    int seen_count = 0;

    while ((read = getline(&line, &len, src)) != -1) {
        if (is_unique(line, seen, seen_count)) {
            fprintf(dest, "%s", line);
            if (seen_count < MAX_LINES) {
                seen[seen_count++] = strdup(line);
            }
        }
    }

    for (int i = 0; i < seen_count; i++) {
        free(seen[i]);
    }
    free(line);
    fclose(src);
    fclose(dest);

    printf("Unique lines copied to '%s'.\n", dest_filename);
    return 0;
}
