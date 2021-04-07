class Solution
{
public:
    bool binarychopsearch(vector<int> &nums, int left, int right, int target)
    {
        if (left == right)
        {
            if (nums[left] == target)
                return true;
        }
        else if (left + 1 == right)
        {
            if (nums[left] == target || nums[right] == target)
                return true;
        }
        else if (nums[(left + right) / 2] > target)
            return binarychopsearch(nums, left, (left + right) / 2, target);
        else
            return binarychopsearch(nums, (left + right) / 2, right, target);
        return false;
    }
    bool search(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len == 1)
            return target == nums[0];
        int k = len;
        for (int i = 1; i < len; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                k = i;
                break;
            }
        }
        if (k == len)
            return binarychopsearch(nums, 0, k - 1, target);
        return binarychopsearch(nums, 0, k - 1, target) || binarychopsearch(nums, k, len - 1, target);
    }
};