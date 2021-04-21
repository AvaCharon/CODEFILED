//欧拉图
/*
class Solution
{
public:
    struct edge
    {
        string from;
        string to;
        edge() {}
        edge(string a, string b)
        {
            from = a;
            to = b;
        }

        bool operator<(const edge b) const
        {
            return to < b.to;
        }
    };
    vector<string> ans;
    unordered_set<string> vis;
    int cnt = 0;

    void dfs(map<string, vector<string>> &ed, string now)
    {
        ans.push_back(now);
        if (cnt == 0)
        {
            return;
        }
        priority_queue<string> pq;
        int len = ed[now].size();
        for (int i = 0; i < len; i++)
            pq.push(ed[now][i]);
        for (int i = 0; i < len; i++)
        {
            if (vis.insert(pq.top()).second)
            {
                cnt--;
                dfs(ed, pq.top());
            }
            pq.pop();
            cnt++;
        }
        return;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        int len = tickets.size();
        map<string, vector<string>> ed;
        for (auto &it : tickets)
        {
            ed[it.first].push_back(it.sasecond);
            cnt++;
        }
        dfs(ed, "JFK");
        return ans;
    }
};
*/
class Solution
{
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

    vector<string> stk;

    void dfs(const string &curr)
    {
        while (vec.count(curr) && vec[curr].size() > 0)
        {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto &it : tickets)
        {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return stk;
    }
};
