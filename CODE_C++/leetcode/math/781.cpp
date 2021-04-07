class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> um;
        for (int it : answers)
            um[it]++;
        int ans = 0;
        for (unordered_map<int, int>::iterator it = um.begin(); it != um.end(); it++)
        {
            if (it->second % (it->first + 1) == 0)
                ans += it->second / (it->first + 1) * (it->first + 1);
            else
                ans += (it->second / (it->first + 1) + 1) * (it->first + 1);
        }
        return ans;
    }
};