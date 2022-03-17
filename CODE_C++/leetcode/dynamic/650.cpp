class Solution
{
public:
    int minSteps(int n)
    {
        int dp[n + 1]; //dp[i]表示第i个字符用的最少操作次数,dp[i]=min(dp[i],dp[i/j]+j)
        memset(dp, 1000, sizeof(dp));
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 1000;
            for (int j = 1; j * j <= i; j++)
                if (i % j == 0)
                    dp[i] = min(min(dp[i], dp[j] + i / j), dp[i / j] + j);
        }
        return dp[n];
    }
};