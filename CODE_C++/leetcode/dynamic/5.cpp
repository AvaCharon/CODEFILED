//最长子串
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len == 0)
            return "";
        if (len == 1)
            return s;
        bool f[len][len + 2]; //f[i][j]=f[i+1][j-1]&&s[i]=s[j]
        memset(f,false,sizeof(f));
        string ans;
        for (int l = 1; l <= len; l++)
        {
            for (int i = 0; i < len; i++)
            {
                int j = i + l - 1;
                if (j > len)
                    break;
                if (l == 1)
                {
                    f[i][j] = true;
                }
                else if (l == 2)
                {
                    if (s[i] == s[j])
                        f[i][j] = true;
                }
                else
                {
                    f[i][j] = f[i + 1][j - 1] && s[i] == s[j];
                }
                if (f[i][j] && (l > ans.size()))
                    ans = s.substr(i, l);
            }
        }
        return ans;
    }
};
