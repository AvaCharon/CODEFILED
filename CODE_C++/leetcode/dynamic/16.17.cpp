class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        if(len==1)return nums[0];
        int maxn=nums[0];
        int t=0;
        for(int i=0;i<len;i++)
        {
            t+=nums[i];
            maxn=max(maxn,t);
            if(t<0)
            {
                t=0;
            }
        }
        return maxn;
    }
};