class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 != len2)
            return false;
        bool dp[len1][len2][len1 + 1];
        memset(dp, false, sizeof(dp));
        for (int k = 1; k <= len1; k++)
        {
            for (int i = 0; i <= len1 - k; i++)
            {
                for (int j = 0; j <= len2 - k; j++)
                {
                    if (k == 1)
                    {
                        dp[i][j][k] = (s1[i] == s2[j]);
                    }
                    else
                    {
                        for (int m = 1; m <= k - 1; m++)
                        {
                            if ((dp[i][j][m] && dp[i + m][j + m][k - m]) || (dp[i][j + k - m][m] && dp[i + m][j][k - m]))
                            {
                                dp[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][len1];
    }
};