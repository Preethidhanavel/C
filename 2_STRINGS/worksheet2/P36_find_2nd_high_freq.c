//36.Find the character with the second highest frequency in a string.
//Input: "aabababa"
//Output: 'b'

#include<stdio.h>
void find_2nd_high_freq(char *a)
{
int i,freq[256]={0};
            for(i=0;a[i];i++)
        {
                freq[a[i]]++;
        }

int b1,b2;
            if(freq[0]>freq[1])
        {
            b1=freq[0];
            b2=freq[1];
        }
            else
        {
            b1=freq[1];
            b2=freq[0];
        }
  for(i=2;i<256;i++)
        {
                if(freq[i] > b1)
                {
                        b2 = b1;
                        b1 = freq[i];
                }
                else if( (freq[i] > b2)&&(freq[i]!=b1) )
                b2 = freq[i];
        }


            for(i=0;i<256;i++)
                if(freq[i]==b2)
                printf("the 2nd high frequent character is %c\n",i);
}
int main()
{
        char a[100];
        printf("Enter the string\n");
        scanf("%s",a);
        find_2nd_high_freq(a);

}