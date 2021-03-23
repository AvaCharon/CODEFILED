//zx fail
/*
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> us;
        for (int j = 0; j <= 9; j++)
        {
            for (int i = 0; i <= 9; i++)
            {
                bool b = true;
                b = us.insert(board[j][i]).second;
                if (!b && isdigit(board[j][i]))
                    return false;
            }
            us.clear();
        }
        for (int j = 0; j <= 9; j++)
        {
            for (int i = 0; i <= 9; i++)
            {
                bool b = true;
                b = us.insert(board[i][j]).second;
                if (!b && isdigit(board[i][j]))
                    return false;
            }
            us.clear();
        }
        for (int k = 0; k <= 9; k++)
        {
            for (int i = k * 3; i < k * 3 + 3; i++)
            {
                for (int j = 3 * (k / 3); j < 3 + 3 * (k / 3); j++)
                {
                    bool b = true;
                    b = us.insert(board[i][j]).second;
                    if (!b && isdigit(board[i][j]))
                        return false;
                }
            }
            us.clear();
        }
        return true;
    }
};
*/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int l[10][10] = {0};
        int c[10][10] = {0};
        int b[10][10] = {0};
        for (int i = 0; i <= 8; i++)
        {
            for (int j = 0; j <= 8; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int t = board[i][j] - '0';
                if (l[i][t])
                    return false;
                if (c[j][t])
                    return false;
                if (b[(i / 3) * 3 + j / 3][t])
                    return false;
                l[i][t]++;
                c[j][t]++;
                b[(i / 3) * 3 + j / 3][t]++;
            }
        }
        return true;
    }
};

//fail
/*
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int l, c, b;
        l = c = b = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int t = board[i][j]-'0';
                if ((l >> t) & 1)
                    return false;
                l = l | (1 << t);
            }
            l = 0;
        }
        for (int j = 0; j <= 9; j++)
        {
            for (int i = 0; i <= 9; i++)
            {
                if (board[i][j] == '.')
                    continue;
                int t = board[i][j]-'0';
                if ((c >> t) & 1)
                    return false;
                c = c | (1 << t);
            }
            c=0;
        }
        for (int k = 0; k <= 9; k++)
        {
            for (int i = k * 3; i < k * 3 + 3; i++)
            {
                for (int j = 3 * (k / 3); j < 3 + 3 * (k / 3); j++)
                {
                    if (board[i][j] == '.')
                        continue;
                    int t = board[i][j]-'0';
                    if ((b >> t) & 1)
                        return false;
                    b = b | (1 << t);
                }
            }
            b=0;
        }
        return true;
    }
};
*/

