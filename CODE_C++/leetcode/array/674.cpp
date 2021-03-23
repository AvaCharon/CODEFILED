class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int ans = 1;
        int maxn = 1;
        int len = nums.size();
        if (len == 0)
            return 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (nums[i + 1] > nums[i])
                ans++;
            else
            {
                maxn = max(maxn, ans);
                ans = 1;
            }
        }
        maxn = max(maxn, ans);
        return maxn;
    }
};