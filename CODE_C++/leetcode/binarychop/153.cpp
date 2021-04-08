class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        for (int i = 1; i < len; i++)
        {
            if (nums[i] < nums[i - 1])
                return nums[i];
        }
        return nums[0];
    }
};