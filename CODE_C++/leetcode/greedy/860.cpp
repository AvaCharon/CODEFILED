class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int len=bills.size();
        int x,y,z;
        x=y=z=0;
        for(int i=0;i<len;i++)
        {
            if(bills[i]==5)
            {
                x++;
            }
            else if(bills[i]==10)
            {
                if(x==0)return false;
                x--;
                y++;
            }
            else if(bills[i]==20)
            {
                if(y)
                {
                    if(x==0)return false;
                    else
                    {
                        y--;
                        x--;
                        z++;
                    }
                }
                else if(x-3>=0)
                {
                    x-=3;
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