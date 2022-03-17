#include <bits/stdc++.h>
using namespace std;

int main()
{
    double l[10] = {80.08,89.601,99.09,108.585,118.1,127.641,137.01,146.225,155.97,165.56};
    double lan = 0;
    for (int i = 0; i < 5; i++)
    {
        lan += (l[i + 5] - l[i]);
    }
    lan /= 25;
    double v = lan * 37000 * 0.001;
    double rv = 345.995;
    double e = (v - rv) / rv;
    cout << v << endl
         << e;
    return 0;
}