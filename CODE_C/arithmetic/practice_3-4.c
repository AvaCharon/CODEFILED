#include<stdio.h>
#include<string.h>
int main(void)
{
    char str[82];
    memset(str,'0',sizeof(str));
    scanf("%s",str);
    int find=1,i=1;
    int len=strlen(str);
    for(;i<len;i++)
    {
        find=1;
        for(int j=0;j<len-i;j++)
        {
            if(str[j]!=str[j+i])
            {
                find=0;
                break;
            }
        }
        if(find==1)break;
    }
    printf("%d",i);
    return 0;
}