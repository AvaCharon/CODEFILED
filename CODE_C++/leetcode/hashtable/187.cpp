class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        unordered_set<string> anss;
        unordered_set<string> us;
        int len = s.size();
        for (int i = 0; i <= len - 10; i++)
        {
            string tmp = "";
            for (int j = 0; j < 10; j++)
                tmp += s[i + j];
            if (!us.insert(tmp).second)
                anss.insert(tmp);
        }
        for (auto &it : anss)
            ans.push_back(it);
        return ans;
    }
};