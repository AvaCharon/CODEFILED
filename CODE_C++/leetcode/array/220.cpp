class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int len = nums.size();
        set<int> rec; //维护滑动窗口
        for (int i = 0; i < len; i++)
        {
            auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t); //防溢出
            if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t)
            {
                return true;
            }
            rec.insert(nums[i]);
            if (i >= k)
            {
                rec.erase(nums[i - k]);
            }
        }
        return false;
    }
};