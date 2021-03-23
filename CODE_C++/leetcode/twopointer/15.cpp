class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < len; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int k = len - 1;
            int target = -nums[i];
            for (int j = i + 1; j < len; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                while (j < k && nums[j] + nums[k] > target)
                {
                    k--;
                }
                if (j == k)
                    break;
                if (nums[j] + nums[k] == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }
};