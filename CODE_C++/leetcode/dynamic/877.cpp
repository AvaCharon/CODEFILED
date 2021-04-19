class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int len = piles.size();
        int f[len][len][2]; //f[i][j]=!f[i+1][j]||!f[i][j-1]
        for (int i = 0; i < len; i++)
        {
            f[i][i][0] = piles[i];
            f[i][i][1] = 0;
        }
        for (int k = 1; k < len; k++)
        {
            for (int i = 0; i < len - k; i++)
            {
                if (f[i][i + k - 1][1] + piles[i + k] > f[i + 1][i + k][1] + piles[i])
                {
                    f[i][i + k][0] = f[i][i + k - 1][1] + piles[i + k];
                    f[i][i + k][1] = f[i][i + k - 1][0];
                }
                else
                {
                    f[i][i + k][0] = f[i + 1][i + k][1] + piles[i];
                    f[i][i + k][1] = f[i + 1][i + k][0];
                }
            }
        }
        return f[0][len - 1][0] > f[0][len - 1][1];
    }
};