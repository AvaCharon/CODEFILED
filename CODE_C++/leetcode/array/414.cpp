class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> s;
        for (auto &num : nums)
        {
            s.insert(num);
            if (s.size() > 3)
                s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};