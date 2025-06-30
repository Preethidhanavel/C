//13.Explain the use of tmpfile() and how it differs from manually creating temporary files. When is it safe or unsafe to use?

#include<stdio.h>
int main()
{
    FILE *temp = tmpfile();
    if(temp == NULL) {
        perror("tmpfile failed");
        return 1;
    }

    fputs("Temporary data", temp);
    rewind(temp);
    char buf[50];
    fgets(buf, sizeof(buf), temp);
    puts(buf);

    fclose(temp);
}