int reverse(int x)
{
    int tx=0;
    int itemp=0;
    int fuhao=1;
    if(x<0)fuhao=-1;
    if(x==INT_MIN)return 0;
    x=x*fuhao;
    for(int i=0;;i++)
    {
        itemp=x%10;
        x=x-itemp;
        x=x/10;
        if(tx>(INT_MAX/10))return 0;
        tx=tx*10+itemp;
        if(x==0)break;
    }
    tx=fuhao*tx;
    return tx;
}
#include<limits.h>
#include<stdio.h>
int main()
{

    int x=reverse(121);
    printf("%d",x);
    return 0;
}
