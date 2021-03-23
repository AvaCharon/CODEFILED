class Solution
{
public:
    int numSquares(int n)
    {
        int f[n + 1]; //f[n]=min(f[n-1]+1,f[n-4]+1,...)
        memset(f, 0, sizeof(f));
        vector<int> squa;
        int cnt = 0;
        for (int i = 1;; i++)
        {
            int tmp = i * i;
            if (tmp > n)
                break;
            f[tmp] = 1;
            squa.push_back(tmp);
            cnt++;
        }
        for (int i = 2; i <= n; i++)
        {
            if (!f[i])
            {
                f[i] = f[i - squa[0]] + 1;
                for (int j = 1; j < cnt && squa[j] < i; j++)
                {
                    f[i] = min(f[i], f[i - squa[j]] + 1);
                }
            }
        }
        return f[n];
    }
};