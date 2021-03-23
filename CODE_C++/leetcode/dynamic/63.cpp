class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0])
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size(); //vector 方法at(n) 返回一个位置n的引用
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 && j == 1)
                {
                    f[i][j] = 1;
                }
                else
                {
                    if (obstacleGrid[i - 1][j - 1])
                        f[i][j] = 0;
                    else
                    {
                        f[i][j] = f[i - 1][j] + f[i][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};