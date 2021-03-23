//Ananagrams uva156
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

map<string,int> cnt;//映射<key,value>
vector<string> words;

string repr(const string&s)//化单词为小写且按字母排序
{
    string ans =s;
    for(int i=0;i<ans.length();i++)
    ans[i]=tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n=0;
    string s;
    while (cin>>s)
    {
        if(s[0]=='#')break;
        words.push_back(s);
        string r =repr(s);
        //使只出现一次的字母组合值为1
        if(!cnt.count(r))cnt[r]=0;
        cnt[r]++;
    }
    vector<string> ans;
    for(int i=0;i<words.size();i++)
    if(cnt[repr(words[i])]==1)ans.push_back(words[i]);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<"\n";
    return 0;
}