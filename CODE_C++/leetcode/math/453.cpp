class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int minn = 0x3f3f3f3f;
        for (int i = 0; i < nums.size(); i++)
        {
            minn = min(minn, nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += (nums[i] - minn);
        }
        return ans;
    }
};
