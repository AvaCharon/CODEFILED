class Solution
{
public:
    bool checkValidString(string s)
    {
        int minn = 0, maxn = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                minn++;
                maxn++;
            }
            else if (ch == '*')
            {
                if (minn)
                {
                    minn--;
                    maxn++;
                }
                else
                    maxn++;
            }
            else
            {
                if (minn)
                {
                    minn--;
                    maxn--;
                }
                else if (maxn)
                    maxn--;
                else
                    return false;
            }
        }
        if (minn == 0)
            return true;
        return false;
    }
};