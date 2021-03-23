class Solution
{
public:
    string fractionToDecimal(long long numerator, long long denominator)
    {
        if (numerator == 0)
            return "0";
        if (numerator == denominator)
            return "1";
        string ans = "";
        if ((numerator > 0) ^ (denominator > 0))
            ans += '-';
        numerator = llabs(numerator);
        denominator = llabs(denominator);
        long long tmp;
        deque<char> tt;
        if (numerator > denominator)
        {
            tmp = numerator / denominator;
            while (tmp)
            {
                tt.push_back('0' + tmp % 10);
                tmp /= 10;
            }
            while (!tt.empty())
            {
                ans += tt.back();
                tt.pop_back();
            }
            numerator %= denominator;
            if (numerator)
                ans += '.';
        }
        else
        {
            ans += '0';

            ans += '.';
        }
        unordered_map<long long, int> us; //us[i]=j表示余数为i的对于小数位置
        us[numerator] = 0;
        int cnt = 1;
        bool iscan = true;
        while (numerator)
        {
            numerator *= 10;
            tmp = numerator / denominator;
            numerator %= denominator;
            tt.push_back('0' + tmp);
            if (us.find(numerator) == us.end())
            {
                us[numerator] = cnt;
                cnt++;
            }
            else
            {
                iscan = false;
                cnt = us[numerator];
                while (cnt--)
                {
                    ans += tt.front();
                    tt.pop_front();
                }
                ans += '(';
                while (!tt.empty())
                {
                    ans += tt.front();
                    tt.pop_front();
                }
                ans += ')';
                break;
            }
        }
        if (numerator == 0 && iscan)
        {
            while (!tt.empty())
            {
                ans += tt.front();
                tt.pop_front();
            }
        }
        return ans;
    }
};

//

