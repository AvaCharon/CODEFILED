#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, s;
int ans[N];
bool vis[N];

struct node
{
    int num;
    int dis;
    node() {}
    node(int a, int b)
    {
        num = a;
        dis = b;
    }
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};

vector<node> mapp[N];

void dij(int s)
{
    priority_queue<node> pq;
    pq.push(node(s, ans[s]));
    while (!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        if (vis[tmp.num])
            continue;
        vis[tmp.num] = true;
        for (int i = 0; i < mapp[tmp.num].size(); i++)
        {
            node y = mapp[tmp.num][i];
            if (ans[y.num] > ans[tmp.num] + y.dis)
            {
                ans[y.num] = ans[tmp.num] + y.dis;
                if (!vis[y.num])
                    pq.push(node(y.num, ans[y.num]));
            }
        }
    }
    return;
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        int c;
        cin >> a >> b >> c;
        mapp[a].push_back(node(b, c));
        mapp[b].push_back(node(a, c));
    }
    for (int i = 1; i <= n; i++)
        ans[i] = 0x7fffffff;
    ans[s] = 0;
    dij(s);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
        int cnt = n;
        while (i != n && cnt--)
            cout << " ";
    }
    return 0;
}