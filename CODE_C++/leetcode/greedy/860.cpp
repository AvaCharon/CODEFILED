//1.0
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int len = bills.size();
        int x, y, z;
        x = y = z = 0;
        for (int i = 0; i < len; i++)
        {
            if (bills[i] == 5)
            {
                x++;
            }
            else if (bills[i] == 10)
            {
                if (x == 0)
                    return false;
                x--;
                y++;
            }
            else if (bills[i] == 20)
            {
                if (y)
                {
                    if (x == 0)
                        return false;
                    else
                    {
                        y--;
                        x--;
                        z++;
                    }
                }
                else if (x - 3 >= 0)
                {
                    x -= 3;
                    z++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//2.0
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int numfive = 0, numten = 0;
        for (auto &bill : bills)
        {
            if (bill == 5)
                numfive++;
            else if (bill == 10)
            {
                if (!numfive)
                    return false;
                numfive--;
                numten++;
            }
            else
            {
                if (numfive > 0 && numten > 0)
                {
                    numfive--;
                    numten--;
                }
                else if (numfive >= 3)
                    numfive -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};