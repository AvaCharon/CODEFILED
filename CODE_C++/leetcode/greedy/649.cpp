class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int len = senate.size();
        int x, y;
        x = y = 0;
        while (1)
        {
            int count = 0;
            for (int i = 0; i < len; i++)
            {
                if (senate[i] == ' ')
                {
                    continue;
                }
                else if (senate[i] == 'R' && x >= 0)
                    y--;
                else if (senate[i] == 'R' && x < 0)
                {
                    count++;
                    x++;
                    senate[i] = ' ';
                }
                else if (senate[i] == 'D' && y >= 0)
                    x--;
                else
                {
                    count++;
                    y++;
                    senate[i] = ' ';
                }
            }
            if(count==0)
            {
            if(x<0)return "Dire";
            else if(y<0)return "Radiant";
            }
        }
    }
};