//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        if(len==0)return 0;
        if(len==1)return 1;
        unordered_set<char> um;
        bool b=false;
        int maxn=0,nmaxn=0;
        string words="";
        for(int i=0;i<len;i++)
        {
            b=um.insert(s[i]).second;
            if(b)
            {
                words+=s[i];
                nmaxn=words.size();
            }
            if(!b)
            {
                maxn=maxn>nmaxn?maxn:nmaxn;
                int j=words.find(s[i]);
                for(int k=0;k<j;k++)
                {
                    um.erase(words[k]);
                }
                words.erase(0,j);
                i=i-nmaxn+j;
            }
        }
        maxn=maxn>nmaxn?maxn:nmaxn;
        return maxn;
    }
};

//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        if(len==0)return 0;
        if(len==1)return 1;
        unordered_set<char> um;
        bool b=false;
        int maxn=0,nmaxn=0;
        string words="";
        for(int i=0;i<len;i++)
        {
            b=um.insert(s[i]).second;
            if(b)
            {
                words+=s[i];
                nmaxn=words.size();
            }
            if(!b)
            {
                maxn=maxn>nmaxn?maxn:nmaxn;
                int j=words.find(s[i]);
                for(int k=0;k<=j;k++)um.erase(words[k]);
                words.erase(0,j+1);
                i=i-nmaxn+j;
            }
        }
        maxn=maxn>nmaxn?maxn:nmaxn;
        return maxn;
    }
};

//滑动窗口+hashtable
int lengthOfLongestSubstring(char * s){
    int i, j = 0, count = 0, max = 0, index[128] = {0}, start = 0;
    for(i=0;s[i]!='\0';i++)     
    {
        if(index[s[i]]>start)   //index用来储存出现重复字符时
        {                       //子串起始下标应移动到的地方
            count = i-start;
            if(count>max)
            {
                max = count;
            }
            start = index[s[i]];
        }
        index[s[i]] = i+1;
    }
    count = i-start;
    return count>max?count:max;
}
