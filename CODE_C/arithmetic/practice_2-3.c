#include<stdio.h>
int main(void)
{
    int n;
    if(scanf("%d",&n)&&(n<=20))
    for(int i=n;i>0;i--)
    {
        for(int k=0;k<=2*(n-i);k++)putchar(' ');
        for(int j=1;j<=(2*i-1);j++)
        {
            putchar('#');  
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}