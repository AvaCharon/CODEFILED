#include<stdio.h>
#include<string.h>
unsigned int MyStrlen(char *p)
{
    unsigned int len=0;
    for(;*p!='\0';p++)
    {
        len++;
    }
    return len;
}

unsigned int MyStrlen2(char s[])
{
    char *p=s;
    while (*p!='\0')
    {
        p++;
    }
    return p-s;
}

int MyStrcmp(char *p1,char *p2)
{
    for(;*p1==*p2;p1++,p2++)
    {
        if(*p1=='\0')return 0;
    }
    return (*p1-*p2);
}

int MyStrcmp2(char s[],char t[])
{
    int i;
    for(i=0;s[i]==t[i];i++)
    {
        if(s[i]=='\0')return 0;
    }
    return (s[i]-t[i]);
}

int main(void)
{
    char s[10],t[10];
    scanf("%s",s);
    scanf("%s",t);
    printf("%d,%d",strcmp(s,t),MyStrcmp2(s,t));
    return 0;
}