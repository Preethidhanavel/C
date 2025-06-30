/*5.How do you handle concurrent access to the same file by multiple C programs? 
Discuss file locking mechanisms available in C and their limitations on different platforms.*/


#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE file;
    DWORD written;
    const char *msg = "Hello from locked program.\r\n";

    file = CreateFile("log.txt", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) 
    {
        printf("Error opening file\n");
        return 1;
    }

    if (!LockFile(file, 0, 0, MAXDWORD, MAXDWORD)) 
    {
        printf("File is locked by another program\n");
        CloseHandle(file);
        return 1;
    }

    printf("Locked. Writing to file...\n");
    SetFilePointer(file, 0, NULL, FILE_END);
    WriteFile(file, msg, strlen(msg), &written, NULL);

    Sleep(3000);

    UnlockFile(file, 0, 0, MAXDWORD, MAXDWORD);
    printf("Unlocked.\n");

    CloseHandle(file);
    return 0;
}
