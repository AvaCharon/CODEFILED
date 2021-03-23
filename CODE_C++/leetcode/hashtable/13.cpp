
class Solution {
public:
    int romanToInt(string s) 
    {
        int result=0;
        map<char,int>romanhash{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0;i<=s.size()-1;i++)
        {
            if(i+1<=s.size())
            {
                int p=romanhash[s[i]];
                int q=romanhash[s[i+1]];
                if(p<q)
                {
                    result=result+q-p;
                    i++;
                }
                else
                {
                    result+=p;
                    if(i+1==(s.size()-1))
                    {
                        result+=q;
                        i++;
                    }
                }
            }
            else
            {
                result+=romanhash[s[i]];
            }
            
        }
        return result;
    }
};