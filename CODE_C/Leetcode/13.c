#include <stdio.h>
#include <string.h>

int romanToInt(char *s)
{
    int i = 0;
    int ires = 0;
    int len = strlen(s);
    int ii = 1;
    int it = 0;
    while (i < len)
    {
        ii = i + 1;
        switch (s[i])
        {
        case 'V':
            ires = ires + 5;
            break;
        case 'L':
            ires += 50;
            break;
        case 'D':
            ires += 500;
            break;
        case 'M':
            ires += 1000;
            break;
        case 'I':
            if (ii < len)
            {
                if (s[ii] == 'V')
                {
                    ires += 4;
                    it = 1;
                }
                else if (s[ii] == 'X')
                {
                    ires += 9;
                    it = 1;
                }
            }
            if (!it)
                ires++;
            break;
        case 'X':
            if (ii < len)
            {
                if (s[ii] == 'L')
                {
                    ires += 40;
                    it = 1;
                }
                else if (s[ii] == 'C')
                {
                    ires += 90;
                    it = 1;
                }
            }
            if (!it)
                ires += 10;
            break;
        case 'C':
            if (ii < len)
            {
                if (s[ii] == 'D')
                {
                    ires += 400;
                    it = 1;
                }
                else if (s[ii] == 'M')
                {
                    ires += 900;
                    it = 1;
                }
            }
            if (!it)
                ires += 100;
            break;
        }
        if(it)i++;
        it=0;
        i++;
    }
    return ires;
}

int main()
{
    char c[10] = "MCMXCVI";
    int a = romanToInt(c);
    printf("%d", a);
    return 0;
}


