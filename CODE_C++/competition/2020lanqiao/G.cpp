#include <bits/stdc++.h>
using namespace std;

bool f(int i)
{
    int day, mon, year;
    bool r = false;
    mon = (i / 100) % 100;
    if (!mon || mon > 12)
        return false;
    year = i / 10000;
    if ((!year % 4 || !year % 100) && year % 400)
        r = true;
    day = i % 100;
    if (!day || day > 31)
        return false;
    if (mon == 2)
    {
        if (!r && day > 28)
            return false;
        else if (r && day > 29)
            return false;
    }
    return true;
}

int main()
{
    int n, ans1, ans2;
    bool find1 = false, find2 = false;
    cin >> n;
    for (int i = n + 1; i < 89991231; i++)
    {
        if (f(i))
        {
            if (!find1 && ((i / 10000000) == i % 10) && ((i / 1000000) % 10 == (i / 10) % 10) && ((i / 100000) % 10 == (i / 100) % 10) && ((i / 10000) % 10 == (i / 1000) % 10))
            {
                find1 = true;
                cout << i << endl;
            }
            if (!find2 && ((i / 1000000) == (i / 10000) % 100) && ((i / 100) % 100 == i % 100) && ((i / 10000000) == i % 10) && ((i / 1000000) % 10 == (i / 10) % 10))
            {
                find2 = true;
                cout << i;
            }
        }
        if (find1 && find2)
            break;
    }
    return 0;
}