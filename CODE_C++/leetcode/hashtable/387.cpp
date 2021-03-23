


//rfind最后一次出现处
class Solution{
    public:
    int firstUniqChar(string s){
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            if(s.find(s[i])==s.rfind(s[i]))return i;
        }
        return -1;
    }
};