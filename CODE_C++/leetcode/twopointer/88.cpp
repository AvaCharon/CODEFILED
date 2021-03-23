class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i, j;
        int p = n + m - 1;
        i = m - 1;
        j = n - 1;
        for (; j >= 0 && i >= 0;)
        {
            if (nums1[i] < nums2[j])
            {
                nums1[p--] = nums2[j--];
            }
            else if (nums1[i] > nums2[j])
            {
                nums1[p--] = nums1[i--];
            }
            else
            {
                nums1[p--] = nums2[j--];
                nums1[p--] = nums1[i--];
            }
        }
        if (i >= 0)
        {
            for (; i >= 0;)
            {
                nums1[p--] = nums1[i--];
            }
        }
        if (j >= 0)
        {
            for (; j >= 0;)
            {
                nums1[p--] = nums2[j--];
            }
        }
        return;
    }
};