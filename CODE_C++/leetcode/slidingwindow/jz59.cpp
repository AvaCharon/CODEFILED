class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        class num
        {
        public:
            int pos;
            int val;
            num(int a, int b) : pos(a), val(b){};
        };
        int len = nums.size();
        deque<num> pq;
        vector<int> ans;
        for (int i = 1; i <= len; i++)
        {
            while (!pq.empty() && nums[i - 1] > pq.back().val)
                pq.pop_back();

            pq.push_back(num(i, nums[i - 1]));

            while (!pq.empty() && pq.front().pos < (i - k + 1))
            {
                pq.pop_front();
            }

            if (i >= k)
            {
                ans.push_back(pq.front().val);
            }
        }
        return ans;
    }
};