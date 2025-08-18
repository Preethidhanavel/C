/*6.Given a binary file containing a list of structures, explain how you would search for and update a specific record in-place, 
without reading the entire file into memory.*/
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    float price;
} Item;

void update_record(const char *filename, int target_id, Item new_data) 
{
    FILE *fp = fopen(filename, "rb+");
    if (!fp) 
    {
        printf("Error opening file.\n");
        return;
    }

    Item temp;
    while (fread(&temp, sizeof(Item), 1, fp) == 1) 
    {
        if (temp.id == target_id) 
        {
            fseek(fp, sizeof(Item), SEEK_CUR); 
            fwrite(&new_data, sizeof(Item), 1, fp); 
            printf("Record updated.\n");
            fclose(fp);
            return;
        }
    }

    printf("Record with ID %d not found.\n", target_id);
    fclose(fp);
}

void print_file(const char *filename) 
{
    FILE *fp = fopen(filename, "r+");
    if (!fp) 
    {
        printf("Error opening file.\n");
        return;
    }

    Item temp;
    printf("File contents:\n");
    while (fread(&temp, sizeof(Item), 1, fp) == 1) 
    {
        printf("ID: %d, Name: %s, Price: %.2f\n", temp.id, temp.name, temp.price);
    }

    fclose(fp);
}

int main() 
{
    const char *filename = "items.bin";
    Item new_data = {2, "Updated Item", 25.50}; 
    print_file(filename);
    update_record(filename, 2, new_data);
    print_file(filename);

    return 0;
}
