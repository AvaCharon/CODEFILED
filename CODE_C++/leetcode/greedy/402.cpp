class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ans;
        stack<int> s;
        int len = num.size();
        bool del[len];
        memset(del, false, sizeof(del));
        if (k == len)
            return "0";
        s.push(0);
        for (int i = 1; i < len; i++)
        {
            while (!s.empty() && num[i] < num[s.top()])
            {
                k--;
                del[s.top()] = true;
                s.pop();
                if (k == 0)
                    break;
            }
            if (k == 0)
                break;
            s.push(i);
        }
        for (int i = 0; i < len - k; i++)
        {
            if (del[i])
                continue;
            if (!ans.size() && num[i] == '0')
                continue;
            ans += num[i];
        }
        if (ans == "")
            return "0";
        return ans;
    }
};