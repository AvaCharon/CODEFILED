/*
class Solution
{
public:
    int numDecodings(string s)
    {
        int len = s.size();
        if (len == 0)
            return 0;
        if (len == 1)
        {
            if (s[0] == '0')
                return 0;
            return 1;
        }
        int f[len + 1][3]; //f[i][0]=max(f[i][1],f[i][2]) f[i][1]=f[i-1],f[i][2]=f[i-2]*2
        memset(f, 0, sizeof(f));
        for (int i = 0; i < len; i++)
        {
            int t = s[i] - '0';
            if (t == 0)
            {
                if (i != 0)
                    f[i][0] = f[i - 1][0];
            }
            else
            {
                if (i == 0)
                    f[i][0] = f[i][1] =f[i][2]= 1;
                else if (i == 1)
                {
                    int r = s[i - 1] - '0';
                    if (((r * 10 + t) <= 26) && r)
                        f[i][0]=2;
                    f[i][2] = 1;
                    f[i][1] = 1;
                }
                else
                {
                    int r = s[i - 1] - '0';
                    if (f[i - 1][0] == 0)
                    {
                        f[i][0] =f[i][1]=f[i][2]= 1;
                        continue;
                    }
                    if (((r * 10 + t) < 27) && r)
                        f[i][2] = f[i - 2][0] * 2;
                    f[i][1] = f[i - 1][1];
                    f[i][0] = f[i][1] +f[i][2];
                }
            }
        }
        return f[len-1][0];
    }
};
*/

class Solution
{
public:
    int numDecodings(string s)
    {
        int len=s.size();
        if(len==0)return 0;
        if (s[0] == '0')
            return 0;
        int pre = 1, curr = 1; //dp[-1] = dp[0] = 1
        for (int i = 1; i < len; i++)
        {
            int tmp = curr;
            if (s[i] == '0')
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    curr = pre;
                else
                    return 0;
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                curr = curr + pre;
            pre = tmp;
        }
        return curr;
    }
};
