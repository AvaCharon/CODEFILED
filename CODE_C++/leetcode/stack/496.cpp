class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> tmp;
        int len2 = nums1.size();
        vector<int> ans(len2, -1);
        unordered_map<int, int> sto;
        int len = nums2.size();
        tmp.push(nums2[0]);
        for (int i = 1; i < len; i++)
        {
            while (!tmp.empty() && nums2[i] > tmp.top())
            {
                sto[tmp.top()] = nums2[i];
                tmp.pop();
            }
            tmp.push(nums2[i]);
        }
        for (int i = 0; i < len2; i++)
        {
            if (sto[nums1[i]])
                ans[i] = sto[nums1[i]];
        }
        return ans;
    }
};