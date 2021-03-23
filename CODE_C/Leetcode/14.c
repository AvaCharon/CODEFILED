#include<stdio.h>
#include<string.h>
#include<malloc.h>

char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize==0)return "";
    int i=0;
    int stop=0;
    for(;;i++)
    {
    for(int j=0;j<strsSize;j++)
    {
        if(i>=strlen(strs[j+1]))
        {
            stop=1;
            break;
        }
        if(strs[j][i]!=strs[j+1][i])
        {
            stop=1;
            break;
        }
    }
    if(stop)break;
    }
    if(i)
    {
    char *ch=(char *)malloc(sizeof(char)*(i+1));
    strncpy(ch,strs[0],i+1);
    return ch;
    }
        return "\0";
}

int main()
{
    char (*c)[10]={"flower","flow","flight"};
    char ch[10]=longestCommonPrefix(c,0);
    printf("%s",ch);
    return 0;
}

//

char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize==0)return "";
    int len=strlen(strs[0]);
    if(len==0)return "";
    if(strsSize==1)return strs[0];
    char *ch=(char *)malloc(sizeof(char)*(len+1));
    strncpy(ch,strs[0],len);//不会帮你以'\0'结束！
    ch[len]='\0';
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<strsSize;j++)
        {
            if(strs[0][i]!=strs[j][i])
            {
                ch[i]='\0';
                return ch;
            }
        }
    }
    return ch;
}
