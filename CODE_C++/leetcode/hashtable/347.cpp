class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> um; //数字、次数
        int maxn = 0;
        for (int it : nums)
        {
            um[it]++;
            maxn = max(maxn, um[it]);
        }
        map<int, vector<int>> m;
        for (auto it : um)
        {
            m[it.second].push_back(it.first);
        }
        int cnt = 0;
        vector<int> ans;
        for (int i = maxn; i >= 0; i--)
        {
            if (m.find(i) != m.end())
            {
                int len = m[i].size();
                cnt += len;
                for (auto &it : m[i])
                    ans.push_back(it);
            }
            if (cnt == k)
                break;
        }
        return ans;
    }
};