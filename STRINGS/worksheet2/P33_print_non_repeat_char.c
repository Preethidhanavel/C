//33.For a stream of characters, print the first non-repeating character at each step.
//Input stream: "aabc"
//Output: "a  b b"

#include <stdio.h>
#include <string.h>


void print_first_occur_nonrepeat(char *s)
{
    int i,x,j,f[256]={0};
                for(i=0;s[i];i++)
            {
                    f[s[i]]++;
                    x=0;
                        for(j=0;j<=i;j++){
 
                            if(f[s[j]]==1){
                                printf("%c ",s[j]);
                                x=1;
                                break;
                            }
                        }
                    if(!x)
                        printf(" ");
            }

printf("\n");
    
}


int main() {
    char s[100];
    printf("Enter the string\n");
    scanf("%s",s);
    print_first_occur_nonrepeat(s);
}