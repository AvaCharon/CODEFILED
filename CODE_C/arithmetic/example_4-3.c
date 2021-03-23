#include<stdio.h>
#define N 20
//4 8 9 5 3 1 2 6 10 7
/*
int n,str[N];
int go(int p,int d,int l);
int main(void)
{
    int k,m;
    while(scanf("%d%d%d",&n,&k,&m)==3&&n)
    {
        for(int i=0;i<n+1;i++)
        {
            str[i]=i;
        }
        int pa=0,pb=n+1,left=n;
        while (left)
        {           
            pa=go(pa,1,k);
            left--;
            pb=go(pb,-1,m);
            printf("%3d",pa);
            if(pb!=pa)
            {
                printf("%3d",pb);
                left--;
            }
        }
    }
    return 0;
}

int go(int p,int d,int l)
{
    int i=0;
        for(int j=1;j<l%n;j++)
    {
        if(str[p+d*j]==0)i++;
    }
    p=p+(d*l)%n;
    do
    {
        p=(p+i)%n;
        i++;
    }while(str[p]==0);
    str[p]=0;
    return p;
}
*/

int n,k,m,str[N];
int go(int p,int d,int l)
{
    while (l--)
    {
        do
        {
            p=(p+d+n-1)%n+1;//注意这个计算方法
        } while (str[p]==0);   
    }
    return p;
}

int main(void)
{
    while (scanf("%d%d%d",&n,&k,&m)==3&&n)
    {
        for(int i=1;i<=n;i++)
        {
            str[i]=i;
        }
        int left=n;
        int pa=n,pb=1;
        while (left)
        {
            pa=go(pa,1,k);
            pb=go(pb,-1,m);
            printf("%3d",pa);
            left--;
            if(pb!=pa)
            {
                printf("%3d",pb);
                left--;
            }
            str[pa]=str[pb]=0;
            if (left)
            {
                printf(",");
            }
        }   
        printf("\n");
    }
    return 0;
}