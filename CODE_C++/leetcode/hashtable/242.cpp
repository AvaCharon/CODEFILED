//数组计数
class Solution {
public:
    bool isAnagram(string s, string t) {
        int len=s.size();
        if(len!=t.size())return false;
        if(s==t)return true;
        int counter[26];
        memset(counter,0,sizeof(counter));
        for(int i=0;i<len;i++)
        {
            counter[s[i]-'a']++;
            counter[t[i]-'a']--;
        }
        for(int i=1;i<26;i++)
        {
            if(counter[i])return false;
        }
        return true;
    }
};

//map
class Solution{
public:
    bool isAnagram(string s, string t) {
        int len=s.size();
        if(len!=t.size())return false;
        if(s==t)return true;
        unordered_map<char,int> a;
        for(int i=0;i<len;i++)
        {
            a[s[i]]++;
            a[t[i]]--;
        }
        for(auto it: a)//增强型for循环，it相当于数组中的一个元素
        {
            if(it.second!=0)return false;
        }
        return true;
    }
};