class Solution
{
public:
    long div(long a, long b)
    {
        if (a < b)
            return 0;
        long test = b;
        int cnt = 1;
        while (a > test + test)
        {
            test += test;
            cnt += cnt;
        }
        return cnt + div(a - test, b);
    }
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
        {
            if (dividend > INT_MIN)
                return -dividend;
            return INT_MAX;
        }
        long a = dividend, b = divisor;
        int sign = 1;
        if ((a < 0 && b > 0) || (a > 0 && b < 0))
            sign = -1;
        long ans = div(abs(a), abs(b));
        if (ans == INT_MIN && sign == -1)
            return INT_MAX;
        return ans * sign;
    }
};