class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        string ans = "";
        for (auto &t : dictionary)
        {
            int i = 0, j = 0;
            while (i <= s.size())
            {
                if (s[i] == t[j])
                {
                    if (j + 1 == t.size() && (t.size() > ans.size() || (t.size() == ans.size() && t < ans)))
                    {
                        ans = t;
                        break;
                    }
                    i++;
                    j++;
                }
                else
                    i++;
            }
        }
        return ans;
    }
};