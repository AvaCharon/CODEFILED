#include<stdio.h>
int array[100][100];//可储存100个100位数
void Inp(int n,int b);
int add(int a,int b,int c);
void Put(int n);
int main(void)
{
    Inp(1,2);
    Inp(2,2);
    add(1,2,3);
    return 0;
}

void Inp(int n,int b)
{
    for(int i=0;i<b;i++)
    {
        printf("Input the No.%d number of the number.",i+1);
        scanf("%d",&array[n][i]);
    }
}

int add(int a,int b,int c)
{
    for(int i=0;i<100;i++)
    {
        array[c][i]=array[a][i]+array[b][i];
    }
    for(int i=0;i<100;i++)
    {
         if(array[c][i]>=10)
        {
            array[c][i+1]++;
            array[c][i]=array[c][i]-10;
        }
    }
    Put(c);
}

void Put(int n)
{
    for(int i=0;i<100;i++)
    {
        printf("%d",array[n][i]);
    }
}