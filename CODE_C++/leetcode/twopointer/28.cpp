class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int len = haystack.size();
        int lenn = needle.size();
        if (lenn == 0)
            return 0;
        if (lenn > len)
            return -1;
        if (lenn == len)
        {
            if (haystack == needle)
                return 0;
            else
                return -1;
        }
        for (int i = 0, j = 0; i < len - lenn + 1; i++)
        {
            if (haystack[i] != needle[j])
                continue;
            else
            {
                int t = i;
                while (j < lenn && haystack[t++] == needle[j++])
                    ;

                if (j == lenn && haystack[t - 1] == needle[j - 1])
                    return i;
                else
                {
                    j = 0;
                }
            }
        }
        return -1;
    }
};