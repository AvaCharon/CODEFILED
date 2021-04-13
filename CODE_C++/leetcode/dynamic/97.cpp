class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3)
            return false;
        bool f[len1 + 2][len2 + 2]; //f[i][j]表示s1的前i个元素和s2的前j个元素是否可交错组成s3的前i+j个元素
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int i = 0; i <= len1; i++)
            for (int j = 0; j <= len2; j++)
            {
                if (i > 0 && s1[i - 1] == s3[i + j - 1])
                    f[i][j] = f[i - 1][j];
                if (j > 0 && s2[j - 1] == s3[i + j - 1])
                    f[i][j] = f[i][j] || f[i][j - 1];
            }
        return f[len1][len2];
    }
};