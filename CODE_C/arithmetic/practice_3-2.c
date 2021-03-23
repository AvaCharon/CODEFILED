/*
#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char c,d;
    float sum=0;
    while ((c=getchar())!=EOF)
    {
        A:
        d=getchar();
        if(isdigit(d)==1)
        {
            if(c=='C')sum=sum+12.01*d;
            if(c=='H')sum=sum+1.008*d;
            if(c=='O')sum=sum+16.00*d;
            if(c=='N')sum=sum+14.01*d;
        }
        else
        {
            if(c=='C')sum=sum+12.01;
            if(c=='H')sum=sum+1.008;
            if(c=='O')sum=sum+16.00;
            if(c=='N')sum=sum+14.01;
            c=d;
            goto A;
        }
    }
    printf("%.3f",sum);
    return 0;
}
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    char str[100];
    memset(str,0,100);
    scanf("%s",str);
    float sum=0,d=0;
    for(int i=0;i<sizeof(str);i++)
    {
        if(isalpha(str[i]))
        {
            if(isdigit(str[i+1]))
            {
                if(isdigit(str[i+2]))
                {
                    d=10*(str[i+1]-'0')+str[i+2]-'0';
                }
                d=str[i+1]-'0';
            }
            else
            {
                d=1;
            }
            switch (str[i])
            {
            case 'C':
                sum=sum+12.01*d;
                break;
            case 'H':
                sum=sum+1.008*d;
                break;
            case 'O':
                sum=sum+16.00*d;
                break;
            case 'N':
                sum=sum+14.01*d;
                break;
            }   
        }
    }
    printf("%.3f",sum);
    return 0;
}