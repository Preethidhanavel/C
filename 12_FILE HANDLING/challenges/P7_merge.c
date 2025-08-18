/*7.Design a robust C program to merge N sorted files (containing sorted lines) into a single sorted file with minimal RAM usage.
 What algorithms and file operations would you use?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_LINE 1024

int main() 
{
    int N;
    char *inputFiles[MAX_FILES];
    FILE *fps[MAX_FILES];
    char lines[MAX_FILES][MAX_LINE];
    int active[MAX_FILES];

    printf("Enter number of sorted files to merge (max %d): ", MAX_FILES);
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        inputFiles[i] = malloc(100);
        printf("Enter name of file %d: ", i + 1);
        fgets(inputFiles[i], 100, stdin);
        inputFiles[i][strcspn(inputFiles[i], "\n")] = 0;
        fps[i] = fopen(inputFiles[i], "r");
        if (!fps[i]) {
            printf("Error opening file %s\n", inputFiles[i]);
            return 1;
        }
        if (fgets(lines[i], MAX_LINE, fps[i]) != NULL)
            active[i] = 1;
        else
            active[i] = 0;
    }

    FILE *out = fopen("merged_output.txt", "w");
    if (!out) {
        printf("Error creating output file.\n");
        return 1;
    }

    while (1) {
        int minIndex = -1;
        for (int i = 0; i < N; i++) {
            if (active[i]) {
                if (minIndex == -1 || strcmp(lines[i], lines[minIndex]) < 0)
                    minIndex = i;
            }
        }

        if (minIndex == -1)
            break;

        fputs(lines[minIndex], out);
        if (fgets(lines[minIndex], MAX_LINE, fps[minIndex]) == NULL)
            active[minIndex] = 0;
    }

    for (int i = 0; i < N; i++) {
        fclose(fps[i]);
        free(inputFiles[i]);
    }
    fclose(out);
    return 0;
}
