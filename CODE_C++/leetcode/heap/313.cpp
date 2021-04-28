class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int k = primes.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> vis;
        pq.push(1);
        int cnt = 1;
        vis.insert(1);
        while (cnt != n)
        {
            int curr = pq.top();
            pq.pop();
            cnt++;
            for (int it : primes)
            {
                if (curr > INT_MAX / it)
                    continue;
                int p = curr * it;
                if (!vis.count(p))
                {
                    vis.insert(p);
                    pq.push(p);
                }
            }
        }
        return pq.top();
    }
};