class NumMatrix
{
public:
    vector<vector<int>> f;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int l = matrix.size();
        if (!l)
            return;
        int c = matrix[0].size();
        if (!c)
            return;
        for (int i = 0; i < l; i++)
            f.push_back(vector<int>(c));
        f[0][0] = matrix[0][0];
        for (int j = 1; j < c; j++)
            f[0][j] = matrix[0][j] + f[0][j - 1];
        for (int i = 1; i < l; i++)
        {
            f[i][0] = f[i - 1][0] + matrix[i][0];
            for (int j = 1; j < c; j++)
            {
                f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 && col1)
            return f[row2][col2] + f[row1 - 1][col1 - 1] - f[row1 - 1][col2] - f[row2][col1 - 1];
        else if (row1)
            return f[row2][col2] - f[row1 - 1][col2];
        else if (col1)
            return f[row2][col2] - f[row2][col1 - 1];
        else
            return f[row2][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */