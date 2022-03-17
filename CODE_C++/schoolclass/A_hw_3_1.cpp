#include <bits/stdc++.h>

using namespace std;

//合并石子
int fun(vector<int> &stone)
{
    int n = stone.size();
    int dp[n + 1][n + 1];
    int W[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
        W[i][i] = stone[i - 1];
    }

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            W[i][j] = W[i][j - 1] + stone[j - 1];

    for (int len = 1; len <= n - 1; len++)
        for (int i = 1; i <= n - len; i++)
        {
            dp[i][i + len] = dp[i + 1][i + len] + W[i][i + len];
            for (int j = i + 1; j <= i + len; j++)
            {
                dp[i][i + len] = min(dp[i][i + len], dp[i][j] + dp[j + 1][i + len] + W[i][i + len]);
            }
        }

    return dp[1][n];
}

int main(void)
{
    vector<int> stone = {1, 3, 5, 2, 4};
    cout << fun(stone);
    return 0;
}