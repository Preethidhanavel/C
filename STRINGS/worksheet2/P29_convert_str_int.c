// 29.Convert a numeric string to an integer without using built-in functions.
//Input: "1234"
//Output: 1234


#include<stdio.h>
void convert_str_int(char *s)
{
        int i,sum=0;
                for(i=0;s[i];i++)
                {
                sum=(sum*10)+(s[i]-48);
                }
        printf("After conversion the integer is %d\n",sum);
}
int main()
{
        char *s;
        printf("Enter the string\n");
        scanf("%s",s);
        convert_str_int(s);

}