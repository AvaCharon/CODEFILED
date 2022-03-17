//dp[i]表示根节点为零，高度为i-1的01树（左0右1）中合法的01串的数量
//dp[n]=dp[n-1](全体左子树)+dp[n-2](右子树的左子树)(斐波那契数列)
class Solution
{
public:
    int findIntegers(int n)
    {
        vector<int> dp(32);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < 31; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        int pre = 0, ans = 0;
        for (int i = 29; i >= 0; i--)
        {
            int tmp = 1 << i;
            if ((n & tmp) != 0) //该位上为1
            {
                ans += dp[i + 1];
                if (pre) //前一位也为1，不合法
                    break;
                pre = 1;
            }
            else
                pre = 0;
            if (!i)
                ans++;
        }
        return ans;
    }
};