class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<int, int> um;
        int len = secret.size();
        int ansa = 0, ansb = 0;
        for (int i = 0; i < len; i++)
        {
            if (secret[i] == guess[i])
            {
                ansa++;
                guess[i] = 'N';
            }
            else
                um[secret[i]]++;
        }
        for (int j = 0; j < len; j++)
        {
            if (guess[j] == 'N')
                continue;
            if (um[guess[j]])
            {
                ansb++;
                um[guess[j]]--;
            }
        }
        string ans = "";
        string tmp = "";
        int cnt = 0;
        if (!ansa)
            ans += '0';
        else
            while (ansa)
            {
                tmp += (char)('0' + ansa % 10);
                ansa /= 10;
                cnt++;
            }
        for (int i = cnt - 1; i >= 0; i--)
            ans += tmp[i];
        ans += 'A';
        tmp = "";
        cnt = 0;
        if (!ansb)
            ans += '0';
        else
            while (ansb)
            {
                tmp += (char)('0' + ansb % 10);
                ansb /= 10;
                cnt++;
            }
        for (int i = cnt - 1; i >= 0; i--)
            ans += tmp[i];
        ans += 'B';
        return ans;
    }
};