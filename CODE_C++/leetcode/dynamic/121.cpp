class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 0;
        int f[n + 2]; //第i天的最大利润 f[i]=max(f[i],prices[i]-prices[j])
        memset(f, 0, sizeof(f));
        f[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (prices[i] > prices[j])
                    f[i] = max(f[i], prices[i] - prices[j]);
            }
            f[i] = max(f[i], f[i - 1]);
        }
        return f[n - 1];
    }
};

//
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 0;
        int f[n + 2]; //第i天的最大利润 f[i]=max(f[i],prices[j]-prices[i])
        memset(f, 0, sizeof(f));
        f[0] = 0;
        int miniprice = prices[0];
        for (int i = 1; i < n; i++)
        {
            f[i] = max(f[i - 1], prices[i] - miniprice);
            miniprice = min(prices[i], miniprice);
        }
        return f[n - 1];
    }
};