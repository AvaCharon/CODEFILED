/*
#include <bits/stdc++.h>
using namespace std;

double d1, c, d2, p;
int n;

int main()
{
    cin >> d1 >> c >> d2 >> p >> n;
    map<double, double> m; //距离，油价
    double p[n],d[n];//油价，距离
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        m[x] = y;
    }
    int i=0;
    for(auto pm : m)
    {
        d[i]=pm.first;
        p[i]=pm.second;
    }
    double mp[n];
    mp[n-1]=p[n-1];
    for(i=n-2;i>=0;i--)
    {
        mp[i]=min(mp[i+1],p[i]);
    }
    double ans=0;
    for(i=0;i<n;)
    {
        if(p[i]=mp[i])
        {
            ans+=(d1-d[i])*p[i];
            break;
        }
        else
        {
            int j=i;
            do
            {
                i++;
            } while (p[j]>p[i]);
            ans+=(d[i]-d[j])*p[j];
        }
    }
    printf("%.2lf",ans);
    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

struct gas
{
    float distance, price;
    gas(float distance1 = 0, float price1 = 0) : distance(distance1), price(price1) {}
};
int n;
float d1, c, d2, p, ans = 0, leftc = 0;

int main()
{
    cin >> d1 >> c >> d2 >> p >> n;
    gas gass[n + 2];
    gass[0].distance = 0;
    gass[0].price = p;
    gass[n + 1].distance = d1;
    for (int i = 1; i <= n; i++)
    {
        cin >> gass[i].distance >> gass[i].price;
    }
    int cnt = 0;
    while (1)
    {
        if (gass[cnt].distance + c * d2 < gass[cnt + 1].distance)
        {
            cout << "No Solution";
            return 0;
        }
        else
        {
            if (cnt == n)
            {
                ans += ((d1 - gass[cnt].distance) / d2 - leftc) * gass[cnt].price;
                printf("%.2lf", ans);
                return 0;
            }
            int next = -1;
            for (int i = cnt + 1; i < n + 1; i++)
            {
                if (gass[cnt].price > gass[i].price)
                {
                    next = i;
                    break;
                }
            }
            if (next == -1) //当前价格最低
            {
                if (gass[cnt].distance + c * d2 >= d1) //直接到终点
                {
                    ans += gass[cnt].price * ((d1 - gass[cnt].distance) / d2 - leftc);
                    printf("%.2lf", ans);
                    return 0;
                }
                else //到最远
                {
                    ans += (c - leftc) * gass[cnt].price;
                    int len = c * d2 + gass[cnt].distance;
                    for (int i = cnt + 1;; i++)
                    {
                        if (len < gass[i].distance)
                        {
                            leftc = c - (gass[i - 1].distance - gass[cnt].distance) / d2;
                            cnt = i - 1;
                            break;
                        }
                    }
                }
            }
            else
            {
                if (gass[cnt].distance + c * d2 >= gass[next].distance)
                {
                    ans += gass[cnt].price * ((gass[next].distance - gass[cnt].distance) / d2 - leftc);
                    leftc = 0;
                    cnt = next;
                }
                else
                {
                    ans += (c - leftc) * gass[cnt].price;
                    int len = c * d2 + gass[cnt].distance;
                    for (int i = cnt + 1;; i++)
                    {
                        if (len < gass[i].distance)
                        {
                            leftc = c - (gass[i - 1].distance - gass[cnt].distance) / d2;
                            cnt = i - 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}