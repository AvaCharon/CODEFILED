//
/*
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        int f[n][m];
        int maxr = 0, maxc = 0, maxs = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j])
                {
                    maxc++;
                    maxr++;
                    for (int k = i; k < n; k++)
                    {
                        if (matrix[k][j])
                            maxr++;
                        else
                        {
                            maxs = max(maxs, maxr * maxc);
                            break;
                        }
                    }
                }
                else
                {
                    maxs = maxc * maxr;
                    maxc = 0;
                }
            }
        }
    }
};
*/
//




//
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        int f[n][m]; //该位置向上有几个连续1
        int g[n][m]; //该位置向左有几个连续1
        int s[n][m];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        memset(s, 0, sizeof(s));
        int maxs = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        f[i][j] = g[i][j] = matrix[i][j];
                    }
                    else
                    {
                        f[0][j] = matrix[0][j];
                        g[0][j] = g[0][j - 1] + 1;
                    }
                    goto A;
                }
                if (j == 0 && i)
                {
                    g[i][0] = matrix[i][0];
                    f[i][0] = f[i - 1][0];
                    goto A;
                }
                if (matrix[i][j])
                {
                    f[i][j] = f[i - 1][j] + 1;
                    g[i][j] = g[i][j - 1] + 1;
                }
            A:
                s[i][j] = f[i][j] * g[i][j];
                maxs = max(maxs, s[i][j]);
            }
        }
        return maxs;
    }
};
