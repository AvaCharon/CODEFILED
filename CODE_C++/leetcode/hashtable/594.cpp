class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int len = nums.size();
        unordered_map<int, int> um;
        sort(nums.begin(), nums.end());
        if (nums[0] == nums[len - 1])
            return 0;
        if (nums[0] + 1 == nums[len - 1])
            return len;
        int prev = nums[0];
        int maxn = 0;
        for (int i = 0; i < len; i++)
        {
            um[nums[i]]++;
            if ((nums[i] - 1 > prev))
            {
                if ((nums[i - 1] - prev == 1))
                    maxn = max(maxn, um[nums[i - 1]] + um[prev]);
                prev = nums[i - 1];
            }
            else if (i == len - 1)
            {
                maxn = um[nums[i]] + um[prev];
            }
        }
        return maxn;
    }
};

//
class Solution 
{
public:
    int findLHS(vector<int>& nums) 
    {
        if (nums.size()==0)  //数组为空直接返回0
        {
            return 0;
        }
        int max_length=0;  //最长河蟹子序列的长度
        map<int,int>temp;
        for (int i=0;i!=nums.size();i++)
        {
            temp[nums[i]]++;
        }
        auto next=temp.begin();  //代表map容器中的后一个位置
        auto before=temp.begin();  //代表map容器中的前一个位置
        next++;  //next在before的下一个位置
        for (;next!=temp.end();next++)  //两两比较相邻的key
        {
            if (next->first-before->first==1)  //如果后一个位置的key比前一个位置的key大1
            {
                max_length=max(max_length,next->second+before->second);  //更新max_length
            }
            before++;
        }
        return max_length;
    }
};