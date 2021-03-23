#include<stdio.h>
int main(void)
{
    int a,b,c;
    do
    {
        if(scanf("%d%d%d",&a,&b,&c)&&(a<=1e6)&&(b<=1e6)&&(c<=100)&&(a!=0))
        printf("%.*f\n",c,(a/(float)b));//受限于double类型精度只能达到16位
    } while (a!=0||b!=0||c!=0);
    return 0;
}