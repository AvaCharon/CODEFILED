class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int len1 = name.size();
        int len2 = typed.size();
        int i, j;
        for (i = 0, j = 0; i < len1; i++, j++)
        {
            if (name[i] != typed[j])
                return false;
            if (name[i] == typed[j + 1] && (i == (len1 - 1) || name[i + 1] != typed[j + 1]))
            {
                do
                {
                    j++;
                } while ((j < len2) && typed[j + 1] == typed[j]);
            }
        }
        if (j != len2)
            return false;
        return true;
    }
};