/*7.Delete a file from the computer.
Input: File name: temp.txt
Output: File 'temp.txt' deleted.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *f=malloc(100*sizeof(char));
    if(f==NULL) return 0;
    printf("Enter the file name:\n");
    scanf(" %s",f);

    remove(f);
    printf("File \'%s\' deleted\n",f);

}