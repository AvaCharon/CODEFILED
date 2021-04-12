//丑数2
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        priority_queue<double, vector<double>, greater<double>> q; //小顶堆（先存后排）
        set<long> s;                                               //哈希表用来去重
        s.insert(1);
        vector<int> mask({2, 3, 5});
        double answer = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int &j : mask)
                if (s.insert(answer * j).second)
                {
                    q.push(answer * j);
                }
            answer = q.top();
            q.pop();
        }
        return answer;
    }
};

//dp+三指针 先排后存
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n);
        dp.at(0) = 1;
        int p_2, p_3, p_5;
        p_2 = p_3 = p_5 = 0;
        for (int i = 1; i < n; ++i)
        {
            dp.at(i) = min(min(2 * dp.at(p_2), 3 * dp.at(p_3)), 5 * dp.at(p_5));
            if (dp.at(i) == 2 * dp.at(p_2))
                ++p_2;
            if (dp.at(i) == 3 * dp.at(p_3))
                ++p_3;
            if (dp.at(i) == 5 * dp.at(p_5))
                ++p_5;
        }
        return dp.at(n - 1);
    }
};
