#include<stdio.h>
void swap(int *a,int *b);//交换两数的值
int main(void)
{
    int a,b;
    printf("Input a and b:");
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("a=%d,b=%d.",a,b);
    return 0;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}