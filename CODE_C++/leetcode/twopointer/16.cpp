class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=99999;
        int minn;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int t;
            for(int j=i+1;j<len;j++)
            {
                int k=len-1;
                if(j>(i+1)&&nums[j]==nums[j-1])
                    continue;
                while (k>j)
                {
                    t=nums[j]+nums[k]+nums[i];
                    if(ans>abs(t-target))
                    {
                        ans=abs(t-target);
                        minn=t;
                    }
                    k--;
                    if(ans==0)return target;
                }
            }
        }
        return minn;
    }
};