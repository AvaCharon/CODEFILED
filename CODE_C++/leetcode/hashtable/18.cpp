//
/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len=nums.size();
        vector<int> ans;
        set<int> us;
        for(int i=0;i<len;i++)
        {
            us.insert(nums[i]);
        }
        auto itn:us;
        for(auto it:us)
        {
            if((*it+*(it+1)+*(it+2)+*(it+3))>=target)itn=it+3;
        }
        for(auto it:us)
    }
};
*/

//
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if ((nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]) > target)
                break;
            if ((nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3]) < target)
                continue;
            for (int j = i + 1; j < len - 2; j++)
            {
                if (j > i+1 && nums[j] == nums[j - 1])
                    continue;
                if ((nums[i] + nums[j] + nums[j + 1] + nums[j + 2]) > target)
                    break;
                if ((nums[i] + nums[j] + nums[len - 1] + nums[len - 2]) < target)
                    continue;
                int left = j + 1;
                int right = len - 1;
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};