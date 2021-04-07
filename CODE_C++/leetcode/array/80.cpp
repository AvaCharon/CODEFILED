class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 2)
            return len;
        int cnt = 1;
        int i = 2, j = 2;
        while (j < len)
        {
            if (nums[i - 2] != nums[j])
            {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};