//
class Solution {
public:
    char findTheDifference(string s, string t) {
        int len=s.size();
        if(len==0)return t[0];
        unordered_set<char> us;
        for(int i=0;i<len;i++)
        {
            us.insert(s[i]);
        }
        for(int i=0;i<=len;i++)
        {
            if(!us.insert(t[i]).second)us.erase(t[i]);
        }
        Iterator it
        return it;
    }
};


//异或运算的特性：

异或自己得0，任何数异或0得自己本身；
具有交换律、结合律，例如 1^2^3^4^2^3^1 = (1^1)^(2^2)^(3^3)^4 = 0^0^0^4 = 0^4 = 4;
总结：异或运算擅长找不同。

class Solution {
public:
    char findTheDifference(string s, string t) {
        for (int i = 0; i < s.size(); ++i) t[0] ^= s[i];
        for (int i = 1; i < t.size(); ++i) t[0] ^= t[i];
        return t[0];
    }
};

