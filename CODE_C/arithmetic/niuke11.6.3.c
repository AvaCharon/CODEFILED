#include <stdio.h>
#define N 1000010
void kp(double num[N], int a, int b)
{
    int i = a;
    int j = b;
    int temp;
    while (i < j)
    {
        while ((num[i] < num[j]) && (i < j))
        {
            j--;
        }
        if (i < j)
        {
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
            i++;
        }
        while (num[i] < num[j] && i < j)
        {
            i++;
        }
        if (i < j)
        {
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
            j--;
        }
    }
    if (i == j)
    {
        kp(num, a, i - 1);
        kp(num, i + 1, b);
    }
    return;
}

int main(void)
{
    int n;
    double num[N];
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %lf", &num[i]);
    }
    kp(num, 0, n - 1);
    double sum = num[0];
    for (int i = 1; i < n - 1; i++)
    {
        double a = (num[i - 1] + num[i + 1]) / 2;
        if (num[i] > a)
            num[i] = a;
        sum = sum + num[i];
    }
    sum = sum + num[n - 1];
    printf("%.10lf", sum);
    return 0;
    
}