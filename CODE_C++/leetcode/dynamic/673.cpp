class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int maxlen = 0, ans = 0;
        vector<int> dp(n), cnt(n); //dp[i]=max(dp[j])+1,cnt[i]=count(dp[i]=max(dp[i]))
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            cnt[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && tmp <= dp[j])
                {
                    if (tmp == dp[j])
                        cnt[i] += cnt[j];
                    else
                    {
                        tmp = dp[j];
                        cnt[i] = cnt[j];
                    }
                }
            }
            dp[i] = tmp + 1;
            if (maxlen <= dp[i])
            {
                if (maxlen < dp[i])
                {
                    maxlen = dp[i];
                    ans = cnt[i];
                }
                else
                    ans += cnt[i];
            }
        }
        return ans;
    }
};