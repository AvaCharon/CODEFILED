#include<stdio.h>
#include<string.h>
#define N 10
int arr[N][N]={{22,55,66,77,88,99,10,12,14},{2,24,6,8,22,12,14,16,18},{18,19,20,21,22,23,24,25,26},{24,25,26,67,22,69,70,71,77},{68,78,79,80,22,25,28,29,30},{16,12,11,10,22,56,57,58,59},{33,34,35,36,22,38,39,40,41}};
int find[N][N][4]={0};//0123分别==上下左右
void Ex(int a,int b);//交换两格
void Dle(int n,char c);//删除某行/列
void Ins(int n,char c);//插入某行/列
void Po(int arr[N][N]);//输出数表
void Search(int i,int j);//输出（i，j）变换后的坐标

int main(void)
{
    Po(arr);
    Dle(3,'r');
    Dle(5,'r');
    Dle(3,'c');
    Dle(6,'c');
    Dle(7,'c');
    Dle(9,'c');
    Po(arr);
    Ins(2,'r');
    Ins(3,'r');
    Ins(5,'r');
    Ins(3,'c');
    Po(arr);
    Search(5,5);
    return 0;
}

void Search(int i,int j)
{
    int k=i,l=j;
    while (find[i][j][0]||find[i][j][1]||find[i][j][2]||find[i][j][3])
    {
        for(;find[i][j][0]>0;)k--,find[i][j][0]--;
        for(;find[i][j][1]>0;)k++,find[i][j][1]--;
        for(;find[i][j][2]>0;)l--,find[i][j][2]--;
        for(;find[i][j][3]>0;)l++,find[i][j][3]--;
    }
    printf("(%d,%d)",k,l);
    return;
}

void Ex(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
    return;
}

void Dle(int n,char c)
{
    if(c=='r')
    {
        for(int i=n-1;i<N-1;i++)
        {
            for(int j=0;j<N;j++)
            {
                arr[i][j]=arr[i+1][j];
                find[i][j][2]++;
            }
        }
        for(int j=0;j<N;j++)
        {
            arr[N-1][j]=0;
        }
    }
    else if(c=='c')
    {
        for(int i=n-1;i<N-1;i++)
        {
            for(int j=0;j<N;j++)
            {
                arr[j][i]=arr[j][i+1];
                find[i][j][0]++;
            }
        }
        for(int j=0;j<N;j++)
        {
            arr[j][N-1]=0;
        }
    }
    return;
}

void Ins(int n,char c)
{
    if(c=='r')
    {
        for(int i=N-1;i>=n;i--)
        {
            for(int j=0;j<N;j++)
            {
                arr[i][j]=arr[i-1][j];
                find[i][j][1]++;
            }
        }
        for(int j=0;j<N;j++)
        {
            arr[n][j]=0;
        }
    }
    else if(c=='c')
    {
        for(int i=N-1;i>=n;i--)
        {
            for(int j=0;j<N;j++)
            {
                arr[j][i]=arr[j][i-1];
                find[i][j][3]++;
            }
        }
        for(int j=0;j<N;j++)
        {
            arr[j][n]=0;
        }
    }
    return;
}

void Po(int arr[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    putchar('\n');
    return;
}

