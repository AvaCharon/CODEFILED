class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> ans(amount + 1, amount + 1);
        int len = coins.size();
        ans[0] = 0;
        for (int j = 1; j <= amount; j++)
        {
            for (int i = 0; i < len; i++)
            {
                if (coins[i] == j)
                    ans[j] = 1;
                else if (coins[i] < j && ans[j - coins[i]] != -1)
                    ans[j] = min(ans[j - coins[i]] + 1, ans[j]);
            }
            if (ans[j] == amount + 1)
                ans[j] = -1;
        }
        return ans[amount];
    }
};