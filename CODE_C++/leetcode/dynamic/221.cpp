class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int f[n + 1][m + 1];
        int num[n + 1][m + 1];
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            f[0][i] = matrix[0][i] - '0';
            num[0][i] = f[0][i];
            ans = max(ans, f[0][i]);
        }
        for (int i = 0; i < n; i++)
        {
            f[i][0] = matrix[i][0] - '0';
            num[i][0] = f[i][0];
            ans = max(ans, f[i][0]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                num[i][j] = matrix[i][j] - '0';
                if (f[i - 1][j - 1] && num[i][j])
                {
                    int tmp = f[i - 1][j - 1];
                    bool isnot = false;
                    while (tmp)
                    {
                        isnot = false;
                        for (int cnt = 1; cnt <= tmp; cnt++)
                        {
                            if (!num[i - cnt][j] || !num[i][j - cnt])
                            {
                                isnot = true;
                                break;
                            }
                        }
                        tmp--;
                        if (!isnot)
                            break;
                    }
                    if (isnot)
                        f[i][j] = num[i][j];
                    else
                    {
                        f[i][j] = tmp + 2;
                    }
                }
                else
                {
                    f[i][j] = num[i][j];
                }
                ans = max(ans, f[i][j]);
            }
        }
        return ans * ans;
    }
};