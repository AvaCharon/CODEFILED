#include<stdio.h>
long fun(int n);

int main(void)
{
    int n;
    printf("Input n:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("%d!=%ld\n",i,fun(i));
    }
    return 0;
}

long fun(int n)
{
    static long p=1;
    p=p*n;
    return p;
}