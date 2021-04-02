class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> ans;
        int len = input.size();
        if (k > len)
            return ans;
        priority_queue<int,vector<int>,greater<int>> q;
        for(int it:input)
            q.push(it);
        for (int i = 0; i < k; i++)
        {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};