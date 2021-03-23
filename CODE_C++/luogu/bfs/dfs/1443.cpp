#include<bits/stdc++.h>
using namespace std;

int mapp[410][410];
int n,m;
int a,b;
int ans=0;

struct point
{
    int x;
    int y;
    point(int x1,int y1):x(x1),y(y1){}
};

bool lea(point a)
{
    if(mapp[a.x][a.y]==-1||mapp[a.x][a.y]>ans)return true;
    return false;
}

bool in(point a)
{
    if(a.x>0&&a.y>0&&a.x<=n&&a.y<=m)return true;
    return false;
}

point operator +(point a,point b)
{
    return point(a.x+b.x,a.y+b.y);
}

const point dir[8]={point(1,2),point(-1,2),point(2,1),point(-2,1),point(1,-2),point(-1,-2),point(2,-1),point(-2,-1)};

queue<point> q;

void dfs(point a)
{
    q.push(a);
    while(!q.empty())
    {
        point now=q.front();
        q.pop();
        ans=mapp[now.x][now.y]+1;
        for(int i=0;i<8;i++)
        {
            point t=now+dir[i];
            if(in(t)&&lea(t))
            {
                q.push(t);
                mapp[t.x][t.y]=ans;
            }
        }
    }
    return;
}

int main()
{
    cin>>n>>m>>a>>b;
    memset(mapp,-1,sizeof(mapp));
    mapp[a][b]=0;
    dfs(point(a,b));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<setiosflags(ios::left)<<setw(5);//左对齐 域宽为5
            cout<<mapp[i][j];
        }
        cout<<endl;
    }
    return 0;
}