/*Make a structure for a student record, where the name can be any length.
 Show how you would allocate and free this structure.*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int age;
} Student;

Student* createStudent(int id, const char *name, int age) 
{
    Student *stu = malloc(sizeof(Student));
    if (stu == NULL) return NULL;

    stu->id = id;
    stu->age = age;

    if (name != NULL) 
    {
        stu->name = malloc(strlen(name) + 1);
        if (stu->name == NULL) 
        {
            free(stu);
            return NULL;
        }
        strcpy(stu->name, name);
    } 
    else 
    {
        stu->name = NULL;
    }

    return stu;
}

void freeStudent(Student *stu) 
{
    if (stu == NULL) return;
    free(stu->name);
    free(stu);
}

int main() 
{
    Student *s = createStudent(1, "Alice Johnson", 20);
    if (s == NULL) 
    {
        printf("Failed to allocate student.\n");
        return 1;
    }

    printf("ID: %d, Name: %s, Age: %d\n", s->id, s->name, s->age);

    freeStudent(s);
}
