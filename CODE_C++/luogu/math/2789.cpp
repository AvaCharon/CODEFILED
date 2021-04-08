//n条直线相交（无三线共点）的情形总数（n<=25）
#include <bits/stdc++.h>
using namespace std;

bool f[10010];
int n, ans;

void cnt(int n, int m)
{
    if (!n)
    {
        if (!f[m])
            ans++;
        f[m] = true;
    }
    else
        for (int i = n; i > 0; i--)
            cnt(n - i, i * (n - i) + m);
    return;
}
int main()
{
    cin >> n;
    cnt(n, 0);
    cout << ans;
    return 0;
}