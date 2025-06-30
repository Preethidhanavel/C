/*18.How would you implement a database-like indexing mechanism to quickly access records in a very large file, 
given only the record’s ID?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
} Record;

typedef struct {
    int id;
    long offset;
} IndexEntry;

int main() 
{
    FILE *fp;
    Record recs[3] = {{1, "Alice"},{2, "Bob"},{3, "Charlie"}};

    fp = fopen("records.dat", "wb");

    for (int i = 0; i < 3; i++) {
        fwrite(&recs[i], sizeof(Record), 1, fp);
    }
    fclose(fp);

    IndexEntry index[MAX_RECORDS];
    int count = 0;

    fp = fopen("records.dat", "rb");
   
    Record temp;
    while (fread(&temp, sizeof(Record), 1, fp) == 1) {
        index[count].id = temp.id;
        index[count].offset = ftell(fp) - sizeof(Record);
        count++;
    }

    int search_id;
    printf("Enter ID to find: ");
    scanf("%d", &search_id);

    long found_offset = -1;
    for (int i = 0; i < count; i++) {
        if (index[i].id == search_id) {
            found_offset = index[i].offset;
            break;
        }
    }

    if (found_offset == -1) {
        printf("Record not found.\n");
    } 
    else {
        fseek(fp, found_offset, SEEK_SET);
        fread(&temp, sizeof(Record), 1, fp);
        printf("Found: ID = %d, Name = %s\n", temp.id, temp.name);
    }

    fclose(fp);
    return 0;
}
