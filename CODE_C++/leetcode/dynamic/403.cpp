class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int MAX = 1e5 + 1;
        int len = stones.size();
        if (len == 1)
            return true;
        if (stones[1] != 1)
            return false;
        bool dp[len + 1][MAX];
        memset(dp, false, sizeof(dp));
        dp[1][0] = true;
        int maxn = 2;
        for (int i = 2; i <= len; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                int k = stones[i - 1] - stones[j - 1];
                if (k >= 1 && k <= maxn)
                {
                    dp[i][k] = dp[j][k] || dp[j][k + 1] || dp[j][k - 1];
                    maxn = max(maxn, k + 1);
                    if (i == len && dp[i][k])
                        return true;
                }
            }
        }
        return false;
    }
};

//official
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i)
        {
            if (stones[i] - stones[i - 1] > i)
            {
                return false;
            }
        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                int k = stones[i] - stones[j];
                if (k > j + 1)
                {
                    break;
                }
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k])
                {
                    return true;
                }
            }
        }
        return false;
    }
};