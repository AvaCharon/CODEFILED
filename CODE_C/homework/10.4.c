#include<stdio.h>
int main(void)
{
    char ch[50];
    int n=0,i=0;
    fgets(ch,sizeof(ch),stdin);
    while (ch[i]!='\0')
    {
        if(ch[i]==' ')n++;
        i++;
    }
    printf("%d",n+1);
    return 0;
}