class SummaryRanges
{
private:
    int nums[10002];

public:
    SummaryRanges()
    {
        memset(nums, -1, sizeof(nums));
    }

    void addNum(int val)
    {
        if (nums[val] == -1)
            nums[val] = val + 1;
        find(val);
    }

    int find(int x)
    {
        if (nums[x] == -1)
            return x;
        nums[x] = find(nums[x]);
        return nums[x];
    }
    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        for (int i = 0; i < 10002; i++)
        {
            if (nums[i] != -1)
            {
                find(i);
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(nums[i] - 1);
                ans.push_back(tmp);
                i = nums[i];
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

/*************************************************************************************************/

//2.0
class SummaryRanges
{
public:
    set<int> nums;
    int p[10005];

    SummaryRanges()
    {
        for (int i = 0; i < 10005; i++)
        {
            p[i] = i;
        }
    }

    void addNum(int val)
    {
        nums.insert(val);
        p[val] = p[val + 1];
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        for (auto num : nums)
        {
            if (!ans.empty() && ans.back()[1] >= num)//跳过区间内的数字
                continue;
            ans.push_back({num, find(num) - 1});
        }
        return ans;
    }

    int find(int x)
    {
        if (x == p[x])
            return x;
        p[x] = find(p[x]);
        return p[x];
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
