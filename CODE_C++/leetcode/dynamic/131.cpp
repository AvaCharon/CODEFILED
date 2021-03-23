class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> temp;
    void getone(const string s, int n)
    {
        int len = s.size();
        if (n >= len)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = n; i < len; i++)
        {
            if (ispalindrome(s, n, i))
            {
                string str = s.substr(n, i - n + 1);
                temp.push_back(str);
                getone(s, i + 1);
                temp.pop_back();
            }
        }
        return;
    }
    bool ispalindrome(const string s, int a, int b)
    {
        for (int i = a, j = b; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        int len = s.size();
        if (!len)
            return ans;
        getone(s, 0);
        return ans;
    }
};