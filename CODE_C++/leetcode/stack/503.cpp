class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> ans(len, -1);
        for (int i = 0; i < len - 1; i++)
        {
            nums.push_back(nums[i]);
        }
        stack<int> tmp;
        tmp.push(0);
        for (int i = 1; i < 2 * len - 1; i++)
        {
            while (!tmp.empty() && nums[tmp.top()] < nums[i])
            {
                ans[tmp.top() % len] = nums[i];
                tmp.pop();
            }
            tmp.push(i);
        }
        return ans;
    }
};