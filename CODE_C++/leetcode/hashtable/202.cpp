class Solution {
public:
    bool isHappy(int n) {
        set<int> a;
        int res=n;
        do
        {
            if(res==1)return true;
            bool b=a.insert(res).second;
            if(!b)
            return false;
            else
            res=getnext(res);
        } while (res);
        return true;
    }
    int getnext(int a)
    {
        int b=0;
        do
        {
            b+=(a%10)*(a%10);
            a=a/10;
        } while (a);
        return b;
    }
};