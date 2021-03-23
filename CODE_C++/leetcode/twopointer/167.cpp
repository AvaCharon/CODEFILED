class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int len = numbers.size();
        int i = 0, j = len - 1;
        vector<int> ans;
        while (i < j)
        {
            int tmp = numbers[i] + numbers[j];
            if (tmp < target)
                i++;
            else if (tmp > target)
                j--;
            else
            {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        return ans;
    }
};