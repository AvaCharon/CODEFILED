class Solution
{
public:
    vector<string> fun(vector<string> &res, int n)
    {
        string ans;
        if (n % 3 && n % 5)
            ans = to_string(n);
        else
        {
            if (!(n % 3))
                ans = "Fizz";
            if (!(n % 5))
                ans += "Buzz";
        }
        res.push_back(ans);
        return res;
    }
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;
        for (int i = 1; i <= n; i++)
            fun(ans, i);
        return ans;
    }
};