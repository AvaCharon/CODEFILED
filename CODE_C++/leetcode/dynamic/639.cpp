class Solution
{
public:
    int mod = 1000000007;
    int numDecodings(string s)
    {
        int len = s.size();
        long long dp[len + 1];
        dp[0] = 1;
        if (s[0] == '*')
            dp[1] = 9;
        else if (s[0] == '0')
            dp[1] = 0;
        else
            dp[1] = 1;
        for (int i = 1; i < len; i++)
        {
            if (s[i] == '*')
            {
                dp[i + 1] = 9 * dp[i];
                if (s[i - 1] == '*')
                    dp[i + 1] += 15 * dp[i - 1];
                else if (s[i - 1] == '1')
                    dp[i + 1] += 9 * dp[i - 1];
                else if (s[i - 1] == '2')
                    dp[i + 1] += 6 * dp[i - 1];
            }
            else if (s[i] == '0')
            {
                dp[i + 1] = 0;
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    dp[i + 1] += dp[i - 1];
                else if (s[i - 1] == '*')
                    dp[i + 1] += 2 * dp[i - 1];
            }
            else
            {
                dp[i + 1] = dp[i];
                if (s[i - 1] == '*')
                {
                    if (s[i] - '0' <= 6)
                        dp[i + 1] += 2 * dp[i - 1];
                    else
                        dp[i + 1] += dp[i - 1];
                }
                else if (s[i - 1] == '1' || (s[i - 1] == '2' && (s[i] - '0' <= 6)))
                    dp[i + 1] += dp[i - 1];
            }
            dp[i + 1] %= mod;
        }
        return dp[len] % mod;
    }
};