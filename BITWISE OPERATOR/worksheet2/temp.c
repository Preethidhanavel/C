#include<stdio.h>
#include<math.h>
#define count(n) log2(n)
int set(int n)
{
    int c=0;
    
    while(n=n&(n-1)){
        c++;
    }
    return c;
}
void find_num(int n)
{
    int c=set(n);
    n=n+1;
    while(c!=set(n))
    n++;
    printf("%d ",n);
}
int main()
{
    int n;
    printf("Enter\n");
    scanf("%d",&n);
    find_num(n);

}

/*
10101101
1011=11
1010=10
1010=10
1001=9
1000=8
0111=7
0000=0

*/