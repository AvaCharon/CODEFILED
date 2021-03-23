#include<stdio.h>
#include<string.h>
#define n 1010
int main(void)
{
    char s[n],t[n];
    scanf("%s",s);
    scanf("%s",t);
    int len=strlen(t);
    int Find=0;
    for(int i=0;i<len;i++)
    {
        static int j=0;
        for(;j<len;j++)
        {
            if(s[i]==t[j])
            {
                Find++;
                break;
            }
        }
    }
    if(Find==strlen(s))printf("Yes.\n");
    else
    {
        printf("No.\n");
    }
    
    return 0;
}