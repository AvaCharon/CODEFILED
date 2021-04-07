class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.size();
        int len2 = text2.size();
        int f[len1 + 1][len2 + 1]; //以i，j结尾最大
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        return f[len1][len2];
    }
};