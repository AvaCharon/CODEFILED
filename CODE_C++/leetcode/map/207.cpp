//拓扑排序O(n+m)
class Solution
{
public:
    vector<int> a; //标记是否已达
    vector<int> b; //标记是否搜索中
    bool fail;
    map<int, vector<int>> vi; //[a,[b,c,d]]:a前有bcd

    void dfs(int cnt)
    {
        if (vi[cnt].empty())
        {
            a[cnt] = 1;
        }
        else
        {
            int len = vi[cnt].size();
            b[cnt] = 1;
            for (int i = 0; i < len; i++)
            {
                if (a[vi[cnt][i]])
                    continue;
                else
                {
                    if (!b[vi[cnt][i]])
                    {
                        dfs(vi[cnt][i]);
                        if (fail)
                            return;
                    }
                    else
                    {
                        fail = true;
                        return;
                    }
                }
            }
            a[cnt] = 1;
            b[cnt] = 0;
        }
        return;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        a.resize(numCourses);
        b.resize(numCourses);
        for (auto &pr : prerequisites)
        {
            vi[pr[0]].push_back(pr[1]);
        }
        for (int i = 0; i < numCourses; i++)
            dfs(i);
        if (fail)
            return false;
        return true;
    }
};

/*
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) 
    {
        visited[u] = 1;
        for (int v: edges[u]) 
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid) 
                {
                    return;
                }
            }
            else if (visited[v] == 1) 
            {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};

*/