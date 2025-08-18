//9.Implement Run-Length Encoding (RLE) for string compression
//Compress a string by replacing consecutive repeated characters with the character followed by the count.
//Example: Input: "aaabbc"
//Output: "a3b2c1"

#include<stdio.h>
#include<string.h>
void remove_repeated(char *s)
{
            int i,j,k;
        
        int n=strlen(s);
        for(i=0;i<n;i++){
            for(j=i+1;j<n;){
                if(s[i]==s[j]){
                    for(k=j;k<n;k++)
                        s[k]=s[k+1];
                    n--;
                    }
                else
                j++;
        }

        }

}
void encoding_str(char *s)
{
     int i=0,j=0,c=0;
    int f[256]={0};
    for(i=0;s[i];i++)
    f[s[i]]++;
    remove_repeated(s);
    for(i=0;s[i];i++)
    printf("%c%d",s[i],f[s[i]]);
}
int main()
{
    char s[100];
    printf("Enter string:\n");
    scanf("%s",s);
    encoding_str(s);
   
}