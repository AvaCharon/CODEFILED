class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int len = s.size();
        int n = wordDict.size();
        if (len == 0)
            return true;
        if (len == 1)
        {
            string t = "";
            t += s[0];
            for (int j = 0; j < n; j++)
            {
                if (t == wordDict[j])
                {
                    return true;
                }
            }
            return false;
        }
        bool find = false;
        string t = "";
        int i = -1;
        for (; i < len - 1;)
        {
            do
            {
                find = false;
                i++;
                t += s[i];
                for (int j = 0; j < n; j++)
                {
                    if (t == wordDict[j])
                    {
                        find = true;
                        t = "";
                        break;
                    }
                }
            } while (!find && i < len - 1);
        }
        if (find && (len - 1 == i))
            return true;
        return false;
    }
};
//错因：aaaaa aaa,aa




//
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        auto wordDictSet = unordered_set<string>();
        for (auto word : wordDict)
        {
            wordDictSet.insert(word);
        }

        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};