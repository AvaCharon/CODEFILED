
//
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> a;
        string words[100000];
        string judge="";
        int j=0,k=0;
        stringstream ss(s);
        while(ss>>words[k])
        {
            if(a.find(words[k])==a.end())
            {
                a[words[k]]='a'+j;
                j++;
            }
            k++;
        }
        if(k!=pattern.size())return false;
        if(k==1)return true;
        for(j=0;j<k;j++)
        {
            char c=a.find(words[j])->second;
            judge+=c;
        }
        for(j=0;j<k;j++)
        {
            if(judge.find(judge[j])!=pattern.find(pattern[j]))return false;
        }
        return true;
    }
};

//用vector容器优化
class Solution {
public:
    int vectorFind(vector<string> &vec,string str){
        if(vec.empty())     return -1;
        for(int i=0;i<vec.size();i++){
            if(vec[i] == str){
                return i;
            }
        }
        return -1;
    }
    bool wordPattern(string pattern, string s) {
        if(pattern.empty() && s.empty())    return true;
        vector<string> str_vec;
        istringstream token(s);
        string ch;
        while(token >> ch){     //提取字符串元素
            str_vec.push_back(ch);
        }
        if(pattern.size() != str_vec.size())    return false;
        for(int i=0;i<pattern.size();i++){  //遍历每个元素，并比较其下标
            if(pattern.find(pattern[i]) != vectorFind(str_vec,str_vec[i])){
                return false;
            }
        }
        return true;
    }
};