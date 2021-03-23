#include<stdio.h>
int main(void)
{
    int a,b,c;
    for(int i=100;i<=999;i++)
    {
        a=i/100;
        b=(i-100*a)/10;
        c=i%10;
        if(i==a*a*a+b*b*b+c*c*c)
        {
            printf("%d is a daffodil.\n",i);
        }
    }
    return 0;
}