//组合数/杨辉三角+前缀和
#include <bits/stdc++.h>
using namespace std;

int t, k, f[2005][2005], ans[2005][2005];

int main()
{
    scanf("%d%d", &t, &k);
    for (int i = 0; i <= 2000; i++)
    {
        f[i][0] = 1;
        f[i][i] = 1;
    }
    f[1][1] = 1;
    for (int i = 2; i <= 2000; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % k;
    for (int i = 1; i <= 2000; i++)
        for (int j = 1; j <= 2000; j++)
        {
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            if (f[i][j] == 0 && i >= j)
                ans[i][j]++;
        }
    int n, m;
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", ans[n][m]);
    }
    return 0;
}