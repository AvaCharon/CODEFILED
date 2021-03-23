#include<stdio.h>
long count=0;
void Hanoi(int n,char a,char b,char c);//将n个圆盘借助C从A移动到B
void Move(int n,char a,char b);//将n号圆盘从A移动到B
int main (void)
{
    int n;
    char a,b,c;
    a='a';
    b='b';
    c='c';
    printf("Input the number of the plate:");
    scanf("%d",&n);
    printf("count = %ld",count);
    Hanoi(n,a,b,c);
    printf("The counts are %ld",count);
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
}
void Move(int n,char a,char b)
{
    printf("Move No.%d plate from %c to %c.\n",n,a,b);
    count++;
}