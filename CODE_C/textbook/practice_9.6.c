#include<stdio.h>
#include<math.h>

float integral(float(*f)(float),float a,float b);//指针指向的是函数
float fun1(float a);
float fun2(float b);

int main(void)
{
    float a,b;
    a=integral(fun1,1,0);
    b=integral(fun2,0,3);
    printf("result1=%f\nresult2=%f",a,b);
    return 0;
}

float integral(float(*f)(float),float a,float b)
{
    float result;
    result=((*f)(a)+(*f)(b))*(fabs(a-b))/2;
    return result;
}

float fun1(float a)
{
    return a*a+1;
}

float fun2(float b)
{
    return b/(b*b+1);
}