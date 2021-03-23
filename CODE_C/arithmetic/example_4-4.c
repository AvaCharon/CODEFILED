#include<stdio.h>
#include<string.h>
int readcode(void);
int readint(int c);
int code[8][1<<8];//【节长】【当前节长编码对应的十进制数】==该编码对应的编码头；如code[2][2]==10对应的编码头
int main(void)
{
    while (readcode())//无法读取编码头时退出
    {
        while (1)
        {
            int len=readint(3);//读取当前小节的编码长
            if(len==0)break;//读取编码为000时退出
            while (1)
            {
                int v=readint(len);//读取当前小节
                if(v==(1<<len)-1)break;//至出现小节长的全1编码
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}

//读取且跳过换行符
int readchar(void)
{
    while (1)
    {
        char ch=getchar();
        if(ch!='\n'&&ch!='\r')return ch;
    }
    
    return 0;
}

//读取编码头
int readcode(void)
{
    memset(code,0,sizeof(code));
    code[1][0]=readchar();//读取节长为1的00对应的编码头
    for(int len=2;len<=7;len++)//从00（code[2][0])开始
    {
        for(int i=0;i<(1<<len)-1;i++)
        {
            int ch=getchar();
            if(ch==EOF)return 0;
            if(ch=='\n'||ch=='\r')return 1;
            code[len][i]=ch;
        }
    }
    return 1;
}

//读取长度为c的编码段并转化为十进制
int readint(int c)
{
    int v=0;
    while (c--)
    {
        v=v*2+readchar()-'0';
    }
    return v;
}