//连通分支数
class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int n, int i)
    {
        visited[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] && !visited[j])
                dfs(isConnected, visited, n, j);
        }
        return;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> visited(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, visited, n, i);
                ans++;
            }
        }
        return ans;
    }
};