class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int tmp = 0;
            for (auto it : nums)
                tmp += (it >> i) & 1;
            if (tmp % 3)
                ans |= (1 << i);
        }
        return ans;
    }
};