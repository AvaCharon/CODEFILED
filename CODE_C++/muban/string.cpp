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

//LCS 最长公共子序列
//LPS 最长公共字符串
//LIS 最长上升子序列
int lengthOfLIS(vector<int> &nums)
{
    int len = 1, n = (int)nums.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] > d[len])
        {
            d[++len] = nums[i];
        }
        else
        {
            int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (d[mid] < nums[i])
                {
                    pos = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            d[pos + 1] = nums[i];
        }
    }
    return len;
}