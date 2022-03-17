class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int c[9][9];
        int l[9][9];
        int b[3][3][9];

        memset(c, 0, sizeof(c));
        memset(l, 0, sizeof(l));
        memset(b, 0, sizeof(b));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int tmp = board[i][j] - '0' - 1;
                    c[j][tmp]++;
                    l[i][tmp]++;
                    b[i / 3][j / 3][tmp]++;
                    if (c[j][tmp] > 1 || l[i][tmp] > 1 || b[i / 3][j / 3][tmp] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};