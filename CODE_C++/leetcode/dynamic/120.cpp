class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int len = triangle.size();
        vector<int> ans(len); //ans=max(anx[j],anx[j-1])+triangle[i][j]
        if (len == 1)
            return triangle[0][0];
        ans[0] = triangle[0][0];
        for (int i = 2; i <= len; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (j == 0)
                    ans[j] += triangle[i - 1][0];
                else if (j == i - 1)
                    ans[j] = ans[j - 1] + triangle[i - 1][j];
                else
                    ans[j] = min(ans[j], ans[j - 1]) + triangle[i - 1][j];
            }
        }
        int minn = ans[0];
        int lenn = ans.size();
        for (int i = 1; i < lenn; i++)
        {
            minn = min(minn, ans[i]);
        }
        return minn;
    }
};