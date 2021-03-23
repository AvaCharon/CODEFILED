class Solution
{
public:
    int l, c;
    vector<vector<int>> vis;
    void dfs(vector<vector<int>> &image, int i, int j, int newColor)
    {
        vis[i][j] = 1;
        if (j > 0 && !vis[i][j - 1] && image[i][j - 1] == image[i][j])
            dfs(image, i, j - 1, newColor);
        if (j < c - 1 && !vis[i][j + 1] && image[i][j + 1] == image[i][j])
            dfs(image, i, j + 1, newColor);
        if (i > 0 && !vis[i - 1][j] && image[i - 1][j] == image[i][j])
            dfs(image, i - 1, j, newColor);
        if (i < l - 1 && !vis[i + 1][j] && image[i + 1][j] == image[i][j])
            dfs(image, i + 1, j, newColor);
        image[i][j] = newColor;
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        l = image.size();
        c = image[0].size();
        for (int i = 0; i < l; i++)
            vis.push_back(vector<int>(c));
        dfs(image, sr, sc, newColor);
        return image;
    }
};