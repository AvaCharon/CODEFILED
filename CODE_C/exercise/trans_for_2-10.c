#include<stdio.h>
int main(void)
{
    int a,b[100]={0};
    scanf("%d",&a);
    for(int i=0;i<100&&a>0;i++)
    {
        b[i]=a%2;
        a=a/2;
    }
    int k;
    for(int i=99;i>=0;i--)
    {
        if(b[i]!=0)
        {
            k=i;
            break;
        }
    }
    for(;k>=0;k--)
    {
        printf("%d",b[k]);
    }
    return 1;
}