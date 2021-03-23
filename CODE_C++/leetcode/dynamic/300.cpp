//最长上升子序列
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = nums.size();
        if (!len)
            return 0;
        int f[len + 1]; //以第i个结尾的最长子序列
        f[0] = 1;
        int ans = f[0];
        for (int i = 1; i < len; i++)
        {
            f[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};

//O(n*log n)
class Solution
{
public:
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
};