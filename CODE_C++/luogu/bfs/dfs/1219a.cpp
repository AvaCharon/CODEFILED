#include <bits/stdc++.h>
int n,cnt=0,a[20];
int vis[20]={0},diagnol[50]={0},diagnor[50]={0};
void dfs(int k);
void output();
int main()
{
    scanf("%d",&n);
    dfs(1);
    printf("%d\n",cnt);
    return 0;
}
void dfs(int k)
{
    int i;
    for(i=1;i<=n;i++)
    if(!vis[i]&&!diagnol[k+i]&&!diagnor[k-i+12])//vis,不能同列。diagnol[i+k],若为1,则该棋子的位置与之前某棋子共/对角线
    {//对于\对角线，行-列可能为负，最小-12，故+12
        a[k]=i;
        vis[i]=1;
        diagnol[k+i]=1;
        diagnor[k-i+12]=1;
        if(k==n)output();
        else dfs(k+1);
        vis[i]=0;//回溯
        diagnol[k+i]=0;
        diagnor[k-i+12]=0;
    }
}
void output()
{
    cnt++;
    if(cnt<4){
    int i;
    printf("%d",a[1]);
    for(i=2;i<=n;i++)
        printf(" %d",a[i]);
    printf("\n");}
}