//9.Print the reverse of a string using recursion
//input:hello
//output:olleh

#include<stdio.h>
#include<string.h>
void reverse_recursion(char *s,char *p)
{
            char c;
            if(s>p)
                return;
            c=*s;
            *s=*p;
            *p=c;
reverse_recursion(s+1,p-1);

}
int main()
{
    char a[100];
    printf("Enter the string\n");
    scanf("%s",a);
    printf("before reversing %s\n",a);
    reverse_recursion(a,a+(strlen(a)-1));
    printf("After reversing %s\n",a);
}