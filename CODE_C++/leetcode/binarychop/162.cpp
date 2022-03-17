class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 2)
            return nums[0] > nums[1] ? 0 : 1;
        int mid = len / 2;
        while (mid != 0 && mid != len - 1)
        {
            int left = mid - 1;
            int right = mid + 1;
            if (nums[mid] > nums[left] && nums[mid] > nums[right])
            {
                return mid;
            }
            else if (nums[mid] < nums[left])
            {
                mid = mid / 2;
            }
            else
                mid += (len - mid) / 2;
        }
        return mid;
    }
};

//
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int i = 0, r = nums.size() - 1;
        while (i < r)
        {
            int mid = i + ((r - i) >> 1);
            if (nums[mid] < nums[mid + 1])
                i = mid + 1;
            else
                r = mid;
        }
        return i;
    }
};