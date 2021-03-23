class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len=nums.size();
        if(len<2||k<1)return false;
        unoredered_set<int> a;
        bool b=false;
        int j=0;
        for(int i=0;i<len;i++)
        {
            b=a.insert(nums[i]).second;
            if(!b)return true;
            if(b)
            {
                if(a.size()>k)a.erase(nums[j++]);
            }
        }
        return false;
    }
};