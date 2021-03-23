//bfs fail
#include<bits/stdc++.h>
using namespace std;

int mapp[7][7];
int f[7][7];
int n,m,t;
int a,b,c,d;
bool vis[7][7];

struct point
{
    int x;
    int y;
    point(int x1,int y1):x(x1),y(y1){}
};

bool in(point a)
{
    if(a.x>0&&a.y>0&&a.x<=n&&a.y<=m)return true;
    return false;
}

bool visit(point a)
{
    if(vis[a.x][a.y])return true;
    return false;
}

point operator +(point a,point b)
{
    return point(a.x+b.x,a.y+b.y);
}

const point dir[4]={point(1,0),point(-1,0),point(0,1),point(0,-1)};

queue<point> q;

void bfs(point a)
{
    q.push(a);
    while(!q.empty())
    {
        point now=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            point t=now+dir[i];
            if(in(t)&&(!visit(t)||(t.x==c&&t.y==d))&&!mapp[t.x][t.y])
            {
                f[t.x][t.y]=f[t.x][t.y]+f[now.x][now.y];
                q.push(t);
            }
        }
        vis[now.x][now.y]=1;
    }
    return;
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
    f[a][b]=1;
    bfs(point(a,b));
    cout<<f[c][d];
    return 0;
}