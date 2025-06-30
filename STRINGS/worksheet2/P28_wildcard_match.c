//28.Match a string against a pattern containing wildcards '*' (any sequence) and '?' (single character).
//Input: Pattern = "g*ks", String = "geeks"
//Output: Match
     

#include <stdio.h>
#include <string.h>

int wildCardRec(char * t, char* p, int n, int m) 
{
  
    if (m == 0)
        return (n == 0);

    if (n == 0) {
        for (int i = 0; i < m; i++)
            if (p[i] != '*')
                return 0;
        return 1;
    }

    if (t[n - 1] == p[m - 1] || p[m - 1] == '?')
        return wildCardRec(t, p, n - 1, m - 1);

    if (p[m - 1] == '*')
        return wildCardRec(t, p, n, m - 1) || 
               wildCardRec(t, p, n - 1, m);
    
    return 0;
}

int wildCard(char * txt, char * pat) {
    int n = strlen(txt);
    int m = strlen(pat);
    return wildCardRec(txt, pat, n, m);
}

int main() {
    char  s[100],p[100];
    printf("Enter the string\n");
    scanf("%s",s);
    printf("Enter the pattern\n");
    scanf("%s",p);
    printf("%s\n",wildCard(s, p) ? "MATCH" : "NOT MATCH"); 
    
}