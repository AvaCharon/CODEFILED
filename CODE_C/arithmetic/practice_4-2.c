/************
*uva201
*square
*************/

#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,m,cs=1;
    while(1)
    {
    printf("Problem %d #\n",cs);
    scanf(" %d",&n);
    int H[n][n-1];
    int V[n-1][n];
    int nosquare=0;
    memset(H,0,sizeof(H));
    memset(V,0,sizeof(V));
    scanf(" %d",&m);
    for(int i=0;i<m;i++)
    {
        char ch;
        int a,b;
        scanf(" %c%d%d",&ch,&a,&b);
        if(ch=='H')H[a-1][b-1]=1;
        else if(ch=='V')
        {
            V[a-1][b-1]=1;
        }
    }
    for(int size=1;size<=n-1;size++)
    {
        int k=n-size;
        int num=0;
        for(int p=0;p<k*k;p++)
        {
            int h=p/k;
            int v=p%k;
            int exits=0;
            int bux=size;
            int bus=size-bux;
            for(int i=h,j=v;i<(h+size)&&j<(h+size);i++,j++)
            {
                if(H[i-bus][j]==1&&H[i+bux][j]==1&&V[i][j-bus]==1&&V[i][j+bux]==1)exits++;
                if(exits==size)num++;
                bux--;
                bus=size-bux;
            }
            if(num!=0)nosquare++;
        }
        if(num!=0)
        {
        printf("%d squares(s) of size %d \n",num,size);
        }
        else if(nosquare==0)
        {printf("No completed squares can be found.\n");}
    }
    printf("******************\n");
    cs++;
    }
    return 0;
}