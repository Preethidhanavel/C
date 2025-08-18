/*12.How would you implement an undo feature for a text file editor written in C, considering file I/O and efficiency?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_UNDO 100

typedef enum { INSERT, DELETE } OperationType;

typedef struct {
    OperationType type;
    int position;
    char *text;
    int length;
} UndoCommand;

char buffer[MAX_BUFFER] = "";
int buffer_len = 0;

UndoCommand undo_stack[MAX_UNDO];
int undo_top = -1;

void push_undo(OperationType type, int pos, const char *text, int len) {
    if (undo_top >= MAX_UNDO - 1) 
    return;
    
    undo_top++;
    undo_stack[undo_top].type = type;
    undo_stack[undo_top].position = pos;
    undo_stack[undo_top].length = len;
    undo_stack[undo_top].text = malloc(len + 1);
    strncpy(undo_stack[undo_top].text, text, len);
    undo_stack[undo_top].text[len] = '\0';
}

void insert_text(int pos, const char *text) {
    int len = strlen(text);
    if (pos < 0 || pos > buffer_len || buffer_len + len >= MAX_BUFFER) 
    return;

    memmove(buffer + pos + len, buffer + pos, buffer_len - pos + 1);
    memcpy(buffer + pos, text, len);
    buffer_len += len;
    push_undo(INSERT, pos, text, len);
}

void delete_text(int pos, int len) {
    if (pos < 0 || pos + len > buffer_len) 
    return;

    char *deleted = malloc(len + 1);
    strncpy(deleted, buffer + pos, len);
    deleted[len] = '\0';
    memmove(buffer + pos, buffer + pos + len, buffer_len - pos - len + 1);
    buffer_len -= len;
    push_undo(DELETE, pos, deleted, len);
    free(deleted);
}

void undo() {
    if (undo_top < 0) 
    return;

    UndoCommand cmd = undo_stack[undo_top--];
    if (cmd.type == INSERT) {
        memmove(buffer + cmd.position, buffer + cmd.position + cmd.length, buffer_len - cmd.position - cmd.length + 1);
        buffer_len -= cmd.length;
    } 
    else if (cmd.type == DELETE) {
        memmove(buffer + cmd.position + cmd.length, buffer + cmd.position, buffer_len - cmd.position + 1);
        memcpy(buffer + cmd.position, cmd.text, cmd.length);
        buffer_len += cmd.length;
    }
    free(cmd.text);
}

void print_buffer() {
    printf("Current Text: %s\n", buffer);
}

int main() 
{
    char cmd;
    while (1) {
        printf("\ni=insert, d=delete, u=undo, p=print, q=quit\nEnter command: ");
        scanf(" %c", &cmd);
        if (cmd == 'i') {
            int pos;
            char text[256];
            printf("Insert position: ");
            scanf("%d", &pos);
            printf("Text to insert: ");
            scanf(" %[^\n]", text);
            insert_text(pos, text);
        } 
        else if (cmd == 'd') {
            int pos, len;
            printf("Delete position: ");
            scanf("%d", &pos);
            printf("Length to delete: ");
            scanf("%d", &len);
            delete_text(pos, len);
        } 
        else if (cmd == 'u') {
            undo();
        } 
        else if (cmd == 'p') {
            print_buffer();
        } 
        else if (cmd == 'q') {
            break;
        }
    }
    while (undo_top >= 0) {
        free(undo_stack[undo_top--].text);
    }
    return 0;
}
