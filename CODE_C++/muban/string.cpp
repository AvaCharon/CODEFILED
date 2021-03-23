//最大子序和
int maxSubArray(vector<int> &nums)
{
    int pre = 0, maxAns = nums[0];
    for (const auto &x : nums)
    {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}

