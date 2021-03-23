//Andy's First Dictionary ,Uva 10815
#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

set<string> dict;//集合

int main()
{
    string s, buf;
    while (cin >> s)
    {
        for (int i = 0; i < s.length(); i++)
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);//转化为小写
            else
                s[i] = ' ';
        stringstream ss(s);//用s定义字符串流ss
        while (ss >> buf)
            dict.insert(buf);
    }
    for(set<string>::iterator it = dict.begin();it !=dict.end();++it)//iterator迭代器用法类似于指针
    cout<<*it<<"\n";
    return 0;
}