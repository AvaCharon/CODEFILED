class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<string>> ans;
        if (n == 0)
            return ans;
        unordered_set<char> vus;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            int len = strs[i].size();
            k = 0;
            for (int j = 0; j < len; j++)
            {
                if (!ans[k].empty())
                {
                    for (int p = 0; p < ans[k].size(); p++)
                    {
                        vus.insert(ans[k][0][p]);
                    }
                }
                if (vus.insert(strs[i][j]).second) //k=1开始
                {
                    j = -1;
                    k++;
                    vus.clear();
                };
            }
            ans[k - 1].push_back(strs[i]);
        }
        return ans;
    }
};

//
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ret;
        unordered_map<long, vector<string>> strsMap;
        for (string s : strs)
        {
            long temp = 0;
            for (char c : s)
            {
                temp += c * c * c * c;
            }
            strsMap[temp].push_back(s);
        }
        for (auto i = strsMap.begin(); i != strsMap.end(); ++i)
        {
            ret.emplace_back(i->second);
        }
        return ret;
    }
};