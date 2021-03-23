/*************
*uva220
*黑白棋
**************/

#include <stdio.h>
char qipan[8][8];
char ctrl;
void find(int i, int j, char c);
void gfind(int i, int j, char c);
int main(void)
{
    for (int i = 0; i < 8; i++)
    {
        scanf(" %s", qipan[i]);
    }
    getchar();
    ctrl = getchar();
    char ch;
    getchar();
    ch = getchar();
    while (ch != 'Q')
    {
        if (ch == 'L')
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (qipan[i][j] == ctrl)
                    {
                        if (ctrl == 'W')
                            find(i, j, 'B');
                        else
                            find(i, j, 'W');
                    }
                }
            }
        }
        else if (ch == 'M')
        {
            int i, j;
            i = getchar() - '0';
            j = getchar() - '0';
            qipan[i][j] = ctrl;
            if (ctrl == 'W')
                gfind(i, j, 'B');
            else
                gfind(i, j, 'W');
            int pw = 0, pb = 0;
            for (int m = 0; m < 8; m++)
            {
                for (int n = 0; n < 8; n++)
                {
                    if (qipan[m][n] == 'W')
                        pw++;
                    else if (qipan[m][n] == 'B')
                        pb++;
                }
            }
            printf("Black-%d,White-%d", pb, pw);
            if (ctrl == 'W')
                ctrl = 'B';
            else
                ctrl = 'W';
        }
        printf("\n");
        ch = getchar();
    }
    for (int i = 0; i < 8; i++)
    {
        printf(" %s", qipan[0]);
        putchar('\n');
    }
    return 0;
}

void find(int i, int j, char c)
{
    for (int p = i - 1; p <= i + 1; p++)
    {
        for (int q = j - 1; q <= j + 1; q++)
        {
            if (qipan[p][q] == c)
            {
                int success = 0;
                int a = p - i, b = q - j;
                int u = i, v = j;
                do
                {
                    u = u + a;
                    v = v + b;
                    if (qipan[u][v] == '-')
                        success = 1;
                } while (qipan[u][v] != '-' && u <= 8 && v <= 8 && u >= 0 && v >= 0);
                if (success)
                    printf("(%d,%d)", u + 1, v + 1);
            }
        }
    }
}

void gfind(int i, int j, char c)
{
    for (int p = i - 1; p <= i + 1; p++)
    {
        for (int q = j - 1; q <= j + 1; q++)
        {
            if (qipan[p][q] == c)
            {
                int a = p - i, b = q - j;
                int u = i, v = j;
                do
                {
                    u = u + a;
                    v = v + b;
                } while (qipan[u][v] != ctrl && u <= 8 && v <= 8 && u >= 0 && v >= 0);
                if (qipan[u][v] == ctrl)
                {
                    a = p - i, b = q - j;
                    u = i, v = j;
                    do
                    {
                        u = u + a;
                        v = v + b;
                        qipan[u][v] = ctrl;
                    } while (qipan[u][v] != ctrl);
                }
            }
        }
    }
}
