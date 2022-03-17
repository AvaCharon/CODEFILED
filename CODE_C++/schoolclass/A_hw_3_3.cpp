#include <bits/stdc++.h>

using namespace std;

int fun(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1);
    for (int i = 1; i <= amount; ++i)
    {
        dp[i] = amount + 1;
        for (auto &coin : coins)
        {
            if (i >= coin)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if (dp[amount] == amount + 1)
        return -1;
    return dp[amount];
}

int main(void)
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << fun(coins, amount);
    return 0;
}