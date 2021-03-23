
//利用string类型的find函数 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len=s.size();
        if(len!=t.size())return false;
        if(len==0)return true;
        for(int i=0;i<len;i++)
        {
            if(s.find(s[i])!=t.find(t[i]))return false;
        }
        return true;
    }
};