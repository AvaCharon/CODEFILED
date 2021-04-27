class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> ans;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int f[len + 1]; //包含nums[i]的最大集的大小
        int maxn = 1;
        int maxv = 0;

        for (int i = 0; i < len; i++)
            f[i] = 1;
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            if (f[i] > maxn)
            {
                maxn = f[i];
                maxv = nums[i];
            }
        }

        //倒序获得目标集
        if (maxn == 1)
        {
            ans.push_back(nums[0]);
            return ans;
        }
        for (int i = len - 1; i >= 0 && maxn > 0; i--)
        {
            if (f[i] == maxn && maxv % nums[i] == 0)
            {
                ans.push_back(nums[i]);
                maxn--;
                maxv = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};