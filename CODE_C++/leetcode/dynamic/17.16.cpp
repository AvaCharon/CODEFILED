/*
class Solution {
public:
    int massage(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        if(len==1)return nums[0];
        int f[len+1];//f[i]=max(f[i],f[j])+nums[i];
        memset(f,0,sizeof(f));
        f[0]=nums[0];
        for(int i=1;i<len;i++)
        {
            for(int j=0;j<i-1;j++)
            {
                f[i]=max(f[i],f[j]);
            }
            f[i]+=nums[i];
        }
        int maxn=f[0];
        for(int i=1;i<len;i++)
        {
            maxn=max(maxn,f[i]);
        }
        return maxn;
    }
};
*/


class Solution {
public:
    int massage(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        if(len==1)return nums[0];
        int f[len+1];//f[i]=max(f[i-1],f[i-2]+nums[i]);
        memset(f,0,sizeof(f));
        f[0]=0;
        f[1]=nums[0];
        bool pre=true;
        for(int i=1;i<len;i++)
        {
            if(!pre)//没拿上一个
            {
                f[i+1]=f[i]+nums[i];
                pre=true;
            }
            else//拿了上一个
            {
                if(f[i]>=f[i-1]+nums[i])
                {
                    f[i+1]=f[i];
                    pre=false;
                }
                else
                {
                    f[i+1]=f[i-1]+nums[i];
                    pre=true;
                }
            }
        }
        return f[len];
    }
};