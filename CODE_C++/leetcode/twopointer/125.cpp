class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len = s.size();
        for (int i = 0, j = len - 1; i < j;)
        {
            if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')))
            {
                if (((s[j] >= 'a') && (s[j] <= 'z')) || ((s[j] >= 'A') && (s[j] <= 'Z')))
                {
                    if ((s[i] != s[j]) && ((s[i] - 32) != s[j]) && ((s[i] + 32) != s[j]))
                        return false;
                    else
                        i++, j--;
                }
                else if ((s[j] >= '0') && (s[j] <= '9'))
                {
                    return false;
                }
                else
                {
                    j--;
                }
            }
            else if ((s[i] >= '0') && (s[i] <= '9'))
            {
                if ((s[j] >= '0') && (s[j] <= '9'))
                {
                    if (s[i] != s[j])
                        return false;
                    else
                        i++, j--;
                }
                else if (((s[j] >= 'a') && (s[j] <= 'z')) || ((s[j] >= 'A') && (s[j] <= 'Z')))
                {
                    return false;
                }
                else
                {
                    j--;
                }
            }
            else
            {
                i++;
            }
        }
        return true;
    }
};