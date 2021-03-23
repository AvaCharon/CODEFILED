#include <bits/stdc++.h>
using namespace std;

bool vis[27];
int n;
int ans[27];
char x[27], y[27], z[27];
bool finish;
int j; //进位

bool allf()
{
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            return false;
    }
    return true;
}

bool lea()
{
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((ans[x[i] - 'A'] + ans[y[i] - 'A'] + t) % n != ans[z[i] - 'A'])
            return false;
        t = (ans[x[i] - 'A'] + ans[y[i] - 'A'] + t) / n;
    }
    return true;
}

bool CHECK()
{
    int A, B, C;
    for (int i = 0; i < n; i++)
    {
        A = ans[x[i] - 'A'];
        B = ans[y[i] - 'A'];
        C = ans[z[i] - 'A'];
        if (A == -1 || B == -1 || C == -1)
            continue;
        if ((A + B) % n != C && (A + B + 1) % n != C)
            return 1;
    }
    return 0;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return;
}

void dfs(int a, int j)
{
    if (finish)
    {
        return;
    }
    if (CHECK())
        return;
    if (allf())
    {
        if (lea())
        {
            print();
            finish = true;
        }
        return;
    }
    int q = x[a] - 'A';
    int p = y[a] - 'A';
    int l = z[a] - 'A';
    if (ans[q] == -1)
    {
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                ans[q] = i;
                dfs(a, j);
                vis[i] = 0;
                ans[q] = -1;
            }
        }
        return;
    }
    else if (ans[p] == -1)
    {
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                ans[p] = i;
                dfs(a, j);
                vis[i] = 0;
                ans[p] = -1;
            }
        }
        return;
    }
    else
    {
        int t = ans[q] + ans[p] + j;
        j = t / n;
        if (ans[l] == -1)
        {
            if (!vis[t % n])
            {
                ans[l] = t % n;
                vis[ans[l]] = 1;
                dfs(a + 1, j);
                vis[ans[l]] = 0;
                ans[l] = -1;
            }
            else
                return;
        }
        else
        {
            if (t % n == ans[l])
                dfs(a + 1, j);
            else
                return;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = n; i >= 1; i--)
    {
        cin >> x[i];
    }
    for (int i = n; i >= 1; i--)
    {
        cin >> y[i];
    }
    for (int i = n; i >= 1; i--)
    {
        cin >> z[i];
    }
    memset(ans, -1, sizeof(ans));
    dfs(1, 0);
    return 0;
}