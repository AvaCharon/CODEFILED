class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        unordered_set<int> us{nums1.begin(),nums1.end()};//用迭代器初始化
        for(auto& it:nums2)
        {
            if(us.find(it)!=us.end())
            {
                us.erase(it);
                a.emplace_back(it);
            }
        }
        return a;
    }
};