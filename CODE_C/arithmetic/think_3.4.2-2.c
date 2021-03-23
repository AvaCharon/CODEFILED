#include<stdio.h>
#include<string.h>//未加头文件，无法运行
#define maxn 1000//数值过大，无法运行
int main(void)
{
    char s[maxn];
    scanf("%s",s);
    int tot = 0;
    int len=strlen(s);
    for(int i=0;i<len;i++)//在for里用strlen（），效率低下
    {
        if(s[i]=='1')tot++;//1未加单引号，结果错误
    }
    printf("%d\n",tot);
}