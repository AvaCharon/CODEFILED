//利用快排的思想，时间复杂度O(n)
//#include <bits/stdc++.h>
//using namespace std;

void asort(int *a, int len)
{
    int i = 0, j = len;
    while (i < j)
    {
        while (i < j && a[j] >= 0)
            j--;
        while (i < j && a[i] < 0)
            i++;
        if (i < j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    return;
}

/*int main()
{
    int a[10] = {0, 1, 4, 5, 8, -9, -8, -7, -5, 4};
    asort(a, 10);
    for (int i = 0; i < 10; i++)
        cout << a[i] << endl;
    return 0;
}*/