#include<stdio.h>
void Hanoi(int n ,char a,char b,char c);//将n个盘子从a借助c移动至b
void Move(int n,char a,char b);//将n号盘子从a移动至b
int main(void)
{
    int n;
    char a,b,c;
    a='a';
    b='b';
    c='c';
    printf("Input the number of the plate:");
    scanf("%d",&n);
    Hanoi(n,a,b,c);
    return 0;
}
void Hanoi(int n,char a,char b,char c)
{
    if(n==1)
    {
        Move(n,a,b);
    }
    else
    {
        Hanoi(n-1,a,c,b);
        Move(n,a,b);
        Hanoi(n-1,c,b,a);
    }
    return 0;
}
void Move(int n,char a,char b)
{
    printf("Move No.%d from %c to %c\n",n,a,b);
    return 0;
}