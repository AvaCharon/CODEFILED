#include<stdio.h>
int main(void)
{
    char c;
    int q=0;
    while ((c=getchar())!=EOF)
    {
        if(c=='"')
        {
            printf("%s",q?"``":"''");
            q=!q;
        }
        else
        {
            printf("%c",c);
        }
    }
    return 0;
}