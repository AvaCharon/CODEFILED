
//set
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        set<int> count;
        int sum1=0,sum2=0;
        for(int i=0;i<nums.size();i++)
        {
            count.insert(nums[i]);
            sum1+=nums[i];
        }
        for(set<int>::iterator it=count.begin();it!=count.end();it++)
        {
            sum2+=*it;
        }
        int result=2*sum2-sum1;
        return result;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        set<int> a;
        bool b;
        for(int i=0;i<nums.size();i++)
        {
            b=a.insert(nums[i]).second;
            if(!b)a.erase(nums[i]);
        }
        return *a.begin();
    }
};

//^
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        if(nums.size()==1)return nums[0];
        int result=nums[0]^nums[1];
        for(int i=2;i<nums.size();i++){
            result^=nums[i];
        }
        return result;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        for(int i=1;i<nums.size();i++)
        {
            nums[0]^=nums[i];
        }
        return nums[0];
    }
};
