//f[i]=max(f[i-1],f[i-2]+nums[i])
class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        if(len==1)return nums[0];
        if(len==2)return max(nums[0],nums[1]);
        int f[len+2];//前i间房子 且抢了第i间 的最大
        memset(f,0,sizeof(f));
        f[0]=nums[0];
        f[1]=nums[1];
        for(int i=2;i<len;i++)
        {
            for(int j=0;j<i-1;j++)
            {
                f[i]=max(f[i],f[j]+nums[i]);
            }
            f[i]=max(f[i-1],f[i]);
        }
        return f[len-1];
    }
};