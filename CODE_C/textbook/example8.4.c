#include<stdio.h>
#define N 5
float Ave(int score[],int n);
void Inp(int score[],int n);
void Rank(int score[],int n);
int score[N];
int main(void)
{
    Inp(score,N);
    Rank(score,N);
    float ave = Ave(score,N);
    printf("The average is %f.",ave);
    return 0;
}

float Ave(int score[],int n)
{
    int temp=0;
    for(int i=0;i<n;i++)
    {
        temp=temp+score[i];
    }
    float result = (float)temp/n;
    return result;
}

void Inp(int score[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Input the score of No.%d student:",i+1);
        scanf("%d",&score[i]);
    }
}

void Rank(int score[],int n)
{
    for(int i=0;i<n;i++)//简单选择排序
    {
        for(int k=i;k<n;k++)
        {
            if(score[i]<score[k])
            {
                int temp=score[i];
                score[i]=score[k];
                score[k]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",score[i]);
    }
}