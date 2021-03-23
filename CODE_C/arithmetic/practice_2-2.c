#include<stdio.h>
int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=10;i<=100;i++)
    {
        if(i%3==a&&i%5==b&&i%7==c)
        {
            printf("%d",i);
            break;
        }
        else if(i=100)
        {
            printf("No answer");
        }
        
    }
    return 0;
}