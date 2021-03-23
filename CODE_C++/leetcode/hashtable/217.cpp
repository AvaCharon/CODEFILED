class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> a;
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            a.insert(nums[i]);
        }
        if(a.size()==len)return false;
        else return true;
    }
};

//
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len=nums.size();
        if(len<2)return false;
        set<int> a;
        bool b=false;
        for(int i=0;i<len;i++)
        {
            b=a.insert(nums[i]).second;
            if(!b)return true;
        }
        return false;
    }
};