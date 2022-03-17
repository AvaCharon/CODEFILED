class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        int res = 0;
        for (char ch : s)
        {
            if (ch == ' ')
            {
                ans = 0;
            }
            else
            {
                ans++;
                res = ans;
            }
        }
        return res;
    }
};