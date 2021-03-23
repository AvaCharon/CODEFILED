#include<stdio.h>
#include<string.h>
#define n 2048
int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);
    int str[n];
    memset(str,0,sizeof(str));
    str[0]=a/b;
    for(int i=1;i<n;i++)
    {
        a=a-b*str[i-1];
        a=a*10;
        str[i]=a/b;
    }
    int j=1;
    int Find;
    for(;j<n;j++)
    {
        Find=1;
        for(int i=1;i<n-j;i++)
        {
            if(str[i]!=str[i+j])
            {
                Find=0;
                break;
            }
        }
        if(Find)break;
    }
    printf("%d.(",str[0]);
    for(int i=1;i<=j;i++)
    {
        printf("%d",str[i]);
    }
    printf("),length=%d",j);
    return 0;
}