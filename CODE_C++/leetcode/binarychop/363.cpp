class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int l = matrix.size();
        int c = matrix[0].size();
        bool lislonger = l > c;

        //预处理前缀和
        int sum[l + 1][c + 1];
        for (int i = 0; i <= c; i++)
            sum[0][i] = 0;
        for (int i = 0; i <= l; i++)
            sum[i][0] = 0;
        for (int i = 1; i <= l; i++)
            for (int j = 1; j <= c; j++)
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + matrix[i - 1][j - 1] - sum[i - 1][j - 1];

        //枚举
        int ans = INT_MIN;
        for (int i = 1; i <= (lislonger ? c : l); i++)
            for (int j = i; j <= (lislonger ? c : l); j++)
            {
                set<int> st;
                st.insert(0);
                for (int g = 1; g <= (lislonger ? l : c); g++)
                {
                    int latter = lislonger ? sum[g][j] - sum[g][i - 1] : sum[j][g] - sum[i - 1][g];
                    auto fore = st.lower_bound(latter - k);
                    if (fore != st.end())
                    {
                        int tmp = latter - *fore;
                        ans = max(ans, tmp);
                    }
                    st.insert(latter);
                }
            }
        return ans;
    }
};