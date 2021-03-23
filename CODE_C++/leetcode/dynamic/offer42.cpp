class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        if(len==1)return nums[0];
        int f[len+1];
        memset(f,0,sizeof(f));
        f[0]=nums[0];
        int maxn=f[0];
        int minn=min(f[0],0);
        for(int i=1;i<len;i++)
        {
            f[i]=f[i-1]+nums[i];
            maxn=max(maxn,f[i]-minn);
            minn=min(minn,f[i]);
        }
        return maxn;
    }
};