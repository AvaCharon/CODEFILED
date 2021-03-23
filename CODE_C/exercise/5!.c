#include<stdio.h>
float fun(int n)
{
    static float f=1;
    f*=n;
    return f;
}
int main()
{
    int i;
    float s;
    for(i=1;i<=5;i++)
    {
        s=fun(i);
    }
    printf("%f",s);
    return 0;
}