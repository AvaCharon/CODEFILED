#include<stdio.h>
int main(void)
{
    char c;
    int i=0,sum=0,j;
    while((c=getchar())!=EOF)
    {
        if(c=='O')i++;
        if(c=='X')i=0;
        j=i;
        sum=sum+i;
    }
    sum=sum-j;
    printf("%d",sum);
    return 0;
}