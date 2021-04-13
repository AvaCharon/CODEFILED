class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans;
        int cnt = 0, cont = 0;
        bool vis[numCourses];
        memset(vis, false, sizeof(vis));
        int pre[numCourses];
        memset(pre, 0, sizeof(pre));
        int len = prerequisites.size();
        bool mapp[numCourses][numCourses];
        memset(mapp, false, sizeof(mapp));
        for (int i = 0; i < len; i++)
        {
            mapp[prerequisites[i][1]][prerequisites[i][0]] = true;
            pre[prerequisites[i][0]]++;
        }
        while (cnt != numCourses)
        {
            for (int i = 0; i < numCourses; i++)
            {
                if (!pre[i] && !vis[i])
                {
                    vis[i] = true;
                    cnt++;
                    ans.push_back(i);
                    for (int j = 0; j < numCourses; j++)
                        if (mapp[i][j])
                            pre[j]--;
                }
            }
            cont++;
            if (cont == numCourses && cnt != numCourses)
            {
                return vector<int>();
            }
        }
        return ans;
    }
};