class Solution
{
public:
    int longestPalindrome(string s)
    {
        int len = s.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return 1;
        unordered_set<char> us;
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (!us.insert(s[i]).second)
            {
                us.erase(s[i]);
                ans += 2;
            }
        }
        if (ans < len)
            ans++;
        return ans;
    }
};

//
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int len = s.size();
        if (len == 0)
            return 0;
        int count[64];
        int ans = 0;
        memset(count, 0, sizeof(count));
        for (int i = 0; i < len; i++)
        {
            count[s[i] - 'A']++;
        }
        for (int i = 0; i < 64; i++)
        {
            ans += count[i] % 2; //奇数个的字符数
        }
        if (ans == 0)
            return len - ans;
        return len - ans + 1;
    }
};