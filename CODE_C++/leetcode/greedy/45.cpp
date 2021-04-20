class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return 0;
        int cnt = 0;
        int target = len - 1;
        int f[len];
        int i = -1;
        do
        {
            i++;
            f[i] = i + nums[i];
        } while (f[i] < target);
        target = i;
        cnt++;
        int j = 0;
        while (target)
        {
            if (f[j] >= target)
            {
                target = j;
                cnt++;
                j = -1;
            }
            j++;
        }
        return cnt;
    }
};