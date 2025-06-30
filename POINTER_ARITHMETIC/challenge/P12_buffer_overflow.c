/*How can you detect buffer overflow in a function that only uses pointer traversal over a character array (no indices)?*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void detect_overflow(char *p,int n)
{
    char *end=p+n;
    while((p<end)&&(*p!='\0')){
        printf("%c",*p);
        p++;}
}
int main()
{
    int n;
    printf("Enter buffer size\n");
    scanf("%d",&n);
    char *s=malloc(n*1);
    if(!s)
        return 0;
    printf("Enter string\n");
    getchar();
    fgets(s,n+1,stdin);
    detect_overflow(s,n);

}