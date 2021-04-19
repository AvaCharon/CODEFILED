/*
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return true;
        int f[len];
        for (int i = len - 1; i >= 0; i--)
        {
            f[i] = i;
            for (int j = 1; j <= nums[i]; j++)
            {
                int tmp = i + j;
                if (tmp < len && tmp != f[tmp])
                    tmp = f[tmp];
                f[i] = max(f[i], tmp);
            }
        }
        return f[0] >= len - 1;
    }
};
*/
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        int ans = 0;
        for (int i = 0; i < len && i <= ans; i++)
        {
            ans = max(ans, nums[i] + i);
            if (ans >= len - 1)
                return true;
        }
        return false;
    }
};