#include <bits/stdc++.h>

using namespace std;

//完全背包
int competebp(vector<int> value, vector<int> weigh, int W)
{
    int kinds = value.size();
    int dp[W + 1] = {0};
    for (int i = 0; i < kinds; i++)
        for (int j = 0; j <= W; j++)
        {
            if (j >= weigh[i])
                dp[j] = max(dp[j], dp[j - weigh[i]] + value[i]);
        }
    return dp[W];
}

//0-1背包
int zobp(vector<int> value, vector<int> weigh, int W)
{
    int kinds = value.size();
    int dp[W + 1][kinds + 1];
    for (int i = 0; i <= W; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= kinds; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j >= weigh[i - 1])
                dp[j][i] = max(dp[j - weigh[i - 1]][i - 1] + value[i - 1], dp[j][i - 1]);
        }
    }
    return dp[W][kinds];
}

//多重背包
int multibp(vector<int> value, vector<int> weigh, vector<int> num, int W)
{
    int kinds = value.size();
    int dp[W + 1][kinds + 1];
    for (int i = 0; i <= W; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= kinds; i++)
    {
        for (int k = 0; k <= num[i]; k++)
            for (int j = 0; j <= W; j++)
            {
                if (j >= k * weigh[i - 1])
                    dp[j][i] = max(dp[j - k * weigh[i - 1]][i - 1] + k * value[i - 1], dp[j][i]);
            }
    }
    return dp[W][kinds];
}