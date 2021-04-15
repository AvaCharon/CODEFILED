/*
class Solution
{
public:
    int ans = 0;
    void dfs(int i, vector<vector<bool>> f, int n, int tmp)
    {
        int len = f[i].size();
        if (!len)
        {
            ans = max(ans, tmp);
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (!f[i][j])
                continue;
            dfs(i, f, n, ++tmp);
        }
        return;
    }
    int findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<vector<bool>> f(n, n);
        for (vector<int> it : edges)
            f[it[0]][it[1]] = true;
        for (int i = 0; i < n; i++)
        {
            dfs(i, f, n, 0);
        }
        return ans;
    }
}
*/

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> ans;
        vector<set<int>> ves(n);
        vector<int> degree(n, 0);

        for (vector<int> it : edges)
        {
            ves[it[0]].insert(it[1]);
            ves[it[1]].insert(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] <= 1)
                q.push(i);

        int left = n;
        while (q.size() != left)
        {
            int len = q.size();
            left -= len;
            for (int i = 0; i < len; i++)
            {
                int tmp = q.front();
                q.pop();
                for (int it : ves[tmp])
                {
                    if (degree[it] > 1)
                    {
                        degree[it]--;
                        if (degree[it] == 1)
                            q.push(it);
                    }
                }
            }
        }
        
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};