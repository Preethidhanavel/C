/*26.Find out how big a file is (in bytes).
Input: File name: a.txt
Output: Size: 36 bytes*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *f=malloc(100*sizeof(char));
    if(f==NULL) return 0;
    printf("File name:");
    scanf(" %s",f);
    FILE *fp=fopen(f,"r");
    if(fp==NULL)
    {
        perror("fopen");
        return 0;
    }
    char c;
    int size=0;
    while((c=fgetc(fp))!=EOF)
        size++;
    printf("The size of file is %d\n",size);
}