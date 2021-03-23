#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x;
    int y;
    point(int x1, int y1) : x(x1), y(y1) {}
};

point operator+(point a, point b)
{
    return point(a.x + b.x, a.y + b.y);
}

const point dir[4] = {point(0, 1), point(1, 0), point(0, -1), point(-1, 0)};

int mapp[33][33];
int vis[33][33];
queue<point> q;
int n;

bool lea(point a)
{
    return !mapp[a.x][a.y] && a.x >= 1 && a.x <= n && a.y >= 1 && a.y <= n;
}

bool visit(point a)
{
    return vis[a.x][a.y];
}

bool edg(point a)
{
    return a.x == 1 || a.x == n || a.y == 1 || a.y == n;
}

bool bfs(point a)
{
    bool inside = 1;
    while (!q.empty())
    {
        q.pop();
    }
    memset(vis, 0, sizeof(vis));

    q.push(a);
    vis[a.x][a.y] = 1;
    while (!q.empty())
    {
        point now = q.front();
        if (edg(now)||mapp[now.x][now.y])
        {
            inside = 0;
            return inside;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            point t = now + dir[i];
            if (!visit(t) && lea(t))
            {
                q.push(t);
                vis[t.x][t.y] = 1;
            }
        }
    }
    return inside;
}

int main()
{
    cin >> n;
    int a, b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mapp[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (bfs(point(i, j)))
            {
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        if (vis[i][j])
                            cout << 2;
                        else
                            cout << mapp[i][j];
                        cout << " ";
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }
}