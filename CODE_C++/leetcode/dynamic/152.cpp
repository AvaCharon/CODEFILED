class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        int fmax[len + 2]; //fmax[i]=max(f[i-1]*i,nums[i]);
        int fmin[len + 2];
        fmax[0] = fmin[0] = nums[0];
        int maxn = fmax[0];
        for (int i = 1; i < len; i++)
        {
            fmax[i] = max(nums[i], max(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]));
            fmin[i] = min(nums[i], min(fmin[i - 1] * nums[i], fmax[i - 1] * nums[i]));
            maxn = max(fmax[i], maxn);
        }
        return maxn;
    }
};

//

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i)
        {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};
