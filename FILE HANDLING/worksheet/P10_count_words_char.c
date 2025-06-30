/*10.Count both the number of words and the number of characters in a file.
Input: File name: info.txt (content: This is a test file.)
Output: Words: 5
Characters: 21*/

#include<Stdio.h>
int main()
{
    char *f=malloc(100*sizeof(char));
    if(f==NULL)
    return 0;
    printf("Enter the file name\n");
    scanf("%s",f);
    FILE*fp=fopen(f,"r");
    if(fp==NULL){
        printf("file doesn't exists\n");
        return 0;
    }
    int word=0,ch=0;
    char c;
    while((c=fgetc(fp))!=EOF)
    {
        ch++;
        if(c==' '||c=='\n')
            word++;
    }
    printf("The number of character and words in file are %d  %d\n",ch,word);
}