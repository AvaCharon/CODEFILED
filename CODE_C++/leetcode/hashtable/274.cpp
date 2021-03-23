class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int ans = 0;
        unordered_map<int, int> um;
        int len = citations.size();
        for (int i = 0; i < len; i++)
        {
            int tmp = citations[i];
            for (int i = 0; i <= tmp; i++)
            {
                um[i]++;
                if (um[i] == i)
                    ans = max(ans, i);
            }
        }
        return ans;
    }
};