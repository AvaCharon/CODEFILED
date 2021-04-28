class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        vector<long> f;
        for (int i = 0;; i++)
        {
            long tmp = pow(i, 2);
            if (tmp > c)
                break;
            if (tmp == c)
                return true;
            f.push_back(tmp);
        }
        for (auto it : f)
        {
            if (binary_search(f.begin(), f.end(), c - it))
                return true;
        }
        return false;
    }
};