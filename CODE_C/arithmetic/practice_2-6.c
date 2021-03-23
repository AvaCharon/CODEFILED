#include<stdio.h>
/* first try fail
int main(void)
{
    int array[9]={1,2,3,4,5,6,7,8,9};
    int abc,def,ghi;
    abc=123;
    def=456;
    ghi=789;
    for(;abc<333;)
    {
        if((def==2*abc)&&(ghi==3*abc))
        {
            printf("%d %d %d",abc,def,ghi);
        }
        if(abc%10==0)abc++;
        abc++;

        abc=array[0]*100+array[1]*10+array[2];
        def=array[3]*100+array[4]*10+array[5];
        ghi=array[6]*100+array[7]*10+array[8];
    }
    return 0;
}
*/

//second try 不够简洁
/*
int a[10];
int main(void)
{
    int x,y,z;
    for(x=123;x<333;x++)
    {
        y=2*x;
        z=3*x;
        a[x/100]=a[(x/10)%10]=a[x%10]=1;
        a[y/100]=a[(y/10)%10]=a[y%10]=1;
        a[z/100]=a[(z/10)%10]=a[z%10]=1;
        int sum=0;
        for(int i=1;i<10;i++)
        {
            sum=sum+a[i];
        }
        if(sum==9)
        {
            printf("%d %d %d\n",x,y,z);
        }
        for(int i=1;i<10;i++)
        {
            a[i]=0;
        }
    }
    return 0;
}
*/

#include<string.h>
int main(void)
{
    int n,x,y;
    scanf("%d",&n);
    int a[n][n];
    memset(a,0,sizeof(a));
    int i=0;
    x=-1;
    y=n-1;
    while (i<n*n)
    {
        while (x+1<n&&!a[x+1][y])
        {
            a[++x][y]=++i;
        }
        while (y-1>=0&&!a[x][y-1])
        {
            a[x][--y]=++i;
        }
        while (x-1>=0&&!a[x-1][y])
        {
            a[--x][y]=++i;
        }
        while (y+1<n&&!a[x][y+1])
        {
            a[x][++y]=++i;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

