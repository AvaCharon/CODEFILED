class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        int i = 0;
        int j = 0;
        while (j < len)
        {
            if (nums[j] != val)
            {
                nums[i++] = nums[j];
            }
            j++;
        }
        return i;
    }
};