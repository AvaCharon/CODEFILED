#include <bits/stdc++.h>
using namespace std;

int main()
{
    double q, u, t;
    cin >> u;
    cin >> t;
    double tmp = sqrt(0.0000183 * 0.0016 / (t * (1 + 0.00822 * sqrt(2 * 9.78 * 981 * t / 9 / 0.0000183 / 0.0016) / 10098)));
    q = (18 * 3.14159 * 0.005 / sqrt(2 * 9.78 * 981) / u) * tmp * tmp * tmp;
    cout << q;
}