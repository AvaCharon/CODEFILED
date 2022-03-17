class Solution
{
public:
    string find(string s) // 返回 s 的描述
    {
        int n = s.size(), cnt = 0;
        char c = '.';
        string ret;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] != c) // 当前 计数值 不为0时，将当前字母的描述计入结果字符串
            {
                if (cnt)
                {
                    ret += to_string(cnt);
                    ret += c;
                }
                // 还原各中间记录
                c = s[i];
                cnt = 1; // 当前位置为新字符串
            }
            else
            {
                cnt++;
            }
        }
        if (cnt) // 若 cnt 不为 0，说明仍有剩余部分未计入
        {
            ret += to_string(cnt);
            ret += c;
        }

        return ret;
    }

    string countAndSay(int n)
    {
        string s = "1";
        n--;

        while (n--)
        {
            s = find(s);
        }
        return s;
    }
};