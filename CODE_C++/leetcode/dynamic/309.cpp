class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (!len)
            return 0;
        int f[len][3]; //持有、冻(前一天卖出)、非冻f[n][0]=max(f[n-1][0],f[n-1][2]-prices[n]),f[n][1]=f[n-1][0]+prices[i],f[n][2]=max(f[n-1][2],f[n-1][1])
        memset(f, 0, sizeof(f));
        f[0][0] = -prices[0];
        for (int i = 1; i < len; i++)
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][2], f[i - 1][1]);
        }
        return max(f[len - 1][1], f[len - 1][2]);
    }
};