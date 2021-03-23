
//
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())return intersect(nums2,nums1);
        unordered_map<int,int> um;
        vector<int> ans;
        for(int num:nums1)
        {
            um[num]++;
        }
        for(int num:nums2)
        {
            if(um.count(num))
            {
                um[num]--;
                ans.emplace_back(num);
                if(um[num]==0)um.erase(num);
            }
        }
        return ans;
    }
};