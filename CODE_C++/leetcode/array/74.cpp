class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int l = matrix.size();
        int c = matrix[0].size();
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] > target)
                    return false;
                if (matrix[i][j] == target)
                    return true;
            }
        return false;
    }
};