class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]);
        int f[len];
        memset(f, 0, sizeof(f));
        f[0] = nums[0];
        f[1] = max(f[0], nums[1]);
        for (int i = 2; i < len-1; i++)
        {
            int j = i % len;
            f[i] = max(f[i - 1], f[i - 2] + nums[j]);
        }
        int maxn = f[len-2];
        memset(f,0,sizeof(f));
        f[len-1]=nums[len-1];
        f[len-2]=max(f[len-1],nums[len-2]);
        for (int i = len-3; i > 0; i--)
        {
            int j = i % len;
            f[i] = max(f[i + 1], f[i + 2] + nums[j]);
        }
        maxn=max(maxn,f[1]);
        return maxn;
    }
};