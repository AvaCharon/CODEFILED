
//dfs success
#include<bits/stdc++.h>
using namespace std;

int mapp[7][7];
int ans;
int n,m,t;
int a,b,c,d;
bool vis[7][7];

int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};

bool in(int a,int b)
{
    if(a>=1&&b>=1&&a<=n&&b<=m)return 1;
    return 0;
}

void dfs(int a,int b)
{
    if(a==c&&b==d)
    {
        ans++;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx=a+dirx[i];
        int ny=b+diry[i];
        if(!vis[nx][ny]&&in(nx,ny)&&!mapp[nx][ny])
        {
            vis[nx][ny]=1;//标记状态
            dfs(nx,ny);//进入下一层（递归）
            vis[nx][ny]=0;//回溯
        }
    }
}

int main()
{
    cin>>n>>m>>t;
    cin>>a>>b>>c>>d;
    for(int i=0;i<t;i++)
    {
        int p,q;
        cin>>p>>q;
        mapp[p][q]=1;
    }
    vis[a][b]=1;
    dfs(a,b);
    cout<<ans;
    return 0;
}