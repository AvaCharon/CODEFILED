//暴力枚举
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0;
        for (auto &p : points)
        {
            unordered_map<int, int> cnt; //cnt[1,2]表示到目前点的距离为1的点有两个
            for (auto &q : points)
            {
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                cnt[dis]++;
            }
            for (auto &[_, m] : cnt) //哈希表的一种遍历法
                ans += m * (m - 1);
        }
        return ans;
    }
};