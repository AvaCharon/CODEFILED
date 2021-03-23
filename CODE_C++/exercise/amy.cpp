#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arrx;
    vector<int> arry;
    int x, y, maxn = 0, minn;
    while (cin >> x)
    {
        cin >> y;
        arrx.push_back(x);
        arry.push_back(y);
    }

    int n = arrx.size();
    int len[n];


    x = arrx[0];
    y = arry[0];
    len[0] = sqrt(x * x + y * y);
    cout << len[0] << endl;
    minn = len[0];
    maxn = len[0];
    for (int i = 1; i < n; i++)
    {
        x = arrx[i];
        y = arry[i];
        len[i] = sqrt(x * x + y * y);
        cout << len[i] << endl;
        minn = min(minn, len[i]);
        maxn = max(maxn, len[i]);
    }
    cout << maxn << endl
         << minn << endl;


    vector<int> cont;
    cont.push_back(0);
    sort(len, len + n);
    int i = 0, cnt = 0; //i频次，cnt当前下标
    do
    {
        if (len[cnt] >= i + 1)
        {
            cout << cont[i++] << endl;
            cont.push_back(0);
        }
        else
        {
            cont[i]++;
            cnt++;
            if(cnt==n)cout<<cont[i]<<endl;
        }
    } while (cnt < n);
    int m = cont.size();
    double ave = (double)n / m;
    cout << ave << endl;
    double tmp = 0;
    for (int i = 0; i < m; i++)
    {
        tmp += (cont[0] - ave) * (cont[0] - ave);
    }
    double stdev = sqrt(tmp / (m - 1));
    cout << stdev << endl;

    return 0;
}