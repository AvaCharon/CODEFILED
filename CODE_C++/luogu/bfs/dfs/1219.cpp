#include <bits/stdc++.h>
using namespace std;
int p[15]; //p[i]第i行在第几列
int h[15], x[29], y[29];
int ans;
int cishu;

void putout(int n)
{
    if (cishu < 3)
    {
        cishu++;
        for (int i = 1; i <= n; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return;
}

void dfs(int a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!h[i] && !x[a + i] && !y[a - i + n])//剪枝
        {
            p[a] = i;
            h[i] = 1;
            x[a + p[a]] = 1;
            y[a - p[a] + n] = 1;
            if (a == n)
            {
                ans++;
                putout(n);
            }
            else
                dfs(a + 1, n);
            h[i] = 0;
            x[a + p[a]] = 0;
            y[a - p[a] + n] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    dfs(1, n);
    cout << ans << endl;
    return 0;
}
