/*9.Dynamic Logging Mechanism
Implement three logging functions (consoleLog, fileLog, networkLog) with a common signature.
Allow the program to select the appropriate logging method dynamically through function pointers.
Demonstrate switching between logging methods at runtime based on user input.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void consoleLog(const char *message);
void fileLog(const char *message);
void networkLog(const char *message);

void (*logFunction)(const char *) = NULL;

void consoleLog(const char *message) {
    printf("[Console] %s\n", message);
}

void fileLog(const char *message) {
    FILE *fp = fopen("log.txt", "a");
    if (fp) {
        fprintf(fp, "[File] %s\n", message);
        fclose(fp);
    } else {
        printf("Error opening log file.\n");
    }
}

void networkLog(const char *message) {
    printf("[Network] %s (simulated send)\n", message);
}

int main() {
    int choice;
    char input[256];

    while (1) {
        printf("\nSelect logging method:\n");
        printf("1 - Console Log\n");
        printf("2 - File Log\n");
        printf("3 - Network Log\n");
        printf("0 - Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            while ((getchar()) != '\n');
            continue;
        }
        if (choice == 0) break;

        switch (choice) {
            case 1: logFunction = consoleLog; break;
            case 2: logFunction = fileLog; break;
            case 3: logFunction = networkLog; break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        printf("Enter message to log: ");
        while ((getchar()) != '\n');
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }
        input[strcspn(input, "\n")] = '\0';

        if (logFunction)
            logFunction(input);
    }

    printf("Exiting logging program.\n");
    return 0;
}
