class Solution
{
public:
    int clumsy(int N)
    {
        int leave = N % 4 - 1;
        int ans = 0;
        int tmp = N / 4;
        if (tmp)
        {
            ans += N * (N - 1) / (N - 2) + N - 3;
            N -= 4;
            for (int i = 1; i < tmp; i++)
            {
                ans -= N * (N - 1) / (N - 2);
                N -= 3;
                ans += N;
                N--;
            }
            switch (leave)
            {
            case 0:
                ans--;
                break;
            case 1:
                ans -= 2;
                break;
            case 2:
                ans -= 6;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (N)
            {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3: 
                return 6;
            }
        }
        return ans;
    }
};