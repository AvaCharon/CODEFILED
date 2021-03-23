class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens=s.size();
        int lent=t.size();
        if(lens==0)return true;
        int f[lent+1][26];
        memset(f,0,sizeof(f));
        for(int j=0;j<26;j++)
        {
            f[lent][j]=-1;
        }
        for(int i=lent-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
            {
                if(t[i]-'a'==j)f[i][j]=i;
                else f[i][j]=f[i+1][j];
            }
        }
        int loc=0;
        for(int i=0;i<lens;i++)
        {
            if(f[loc][s[i]-'a']==-1)return false;
            loc=f[loc][s[i]-'a']+1;
        }
        return true;
    }
};