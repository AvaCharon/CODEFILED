#include <bits/stdc++.h>
using namespace std;

struct bigintnode
{
    bigintnode *pre = nullptr;
    bigintnode *next = nullptr;
    int val;
    bigintnode()
    {
        val = 0, next = nullptr;
        pre = nullptr;
    }
};

struct bigint
{
    bigintnode *begin = nullptr;
    bigintnode *end = nullptr;
    int symbol = 1; //1为正0为负
    int figure = 0;
    bigint() { begin = nullptr, end = nullptr, symbol = 1, figure = 0; }
};

bigint adda(bigint a, bigint b) //a>b
{
    bigintnode *pta = a.begin;
    bigintnode *ptb = b.begin;
    bigint ans;
    ans.begin = new bigintnode;
    ans.symbol = a.symbol;
    bigintnode *ptans = ans.begin;
    int tmp = 0;
    while (pta != nullptr)
    {
        if (ptb != nullptr)
        {
            ptans->val = pta->val + ptb->val + tmp;
            tmp = 0;
            if (ptans->val > 999)
            {
                tmp = ptans->val / 1000;
                ptans->val %= 1000;
            }
            pta = pta->next;
            ptb = ptb->next;
            if (pta == nullptr)
                ans.end = ptans;
            bigintnode *ptnext = new bigintnode;
            bigintnode *ppt = ptans;
            ptans->next = ptnext;
            ptans = ptnext;
            ptans->pre = ppt;
        }
        else
        {
            ptans->val = pta->val + tmp;
            tmp = 0;
            if (ptans->val > 999)
            {
                tmp = ptans->val / 1000;
                ptans->val %= 1000;
            }
            pta = pta->next;
            if (pta == nullptr)
                ans.end = ptans;
            bigintnode *ptnext = new bigintnode;
            bigintnode *ppt = ptans;
            ptans->next = ptnext;
            ptans = ptnext;
            ptans->pre = ppt;
        }
    }
    return ans;
}

void pprint(bigint a)
{
    bigintnode *pt = a.end;
    while (pt != nullptr)
    {
        cout << pt->val << ',';
        pt = pt->pre;
    }
    return;
}

int main()
{
    while (1)
    {
        bigint bia, bib;
        bia.begin = new bigintnode;
        bib.begin = new bigintnode;
        char c;

        cin >> c;
        if (c == '-')
            bia.symbol = 0;
        else
            cin.putback(c);
        bigintnode *ptn = bia.begin;
        while (1)
        {
            int tmp;
            cin >> tmp;
            ptn->val = tmp;
            if (cin.get() == '\n')
                break;
            bigintnode *pt = new bigintnode;
            ptn->next = pt;
            bia.figure += 3;
        }
        bia.figure += ptn->val / 10;

        char ch;
        cin >> ch;

        cin >> c;
        if (c == '-')
            bib.symbol = 0;
        else
            cin.putback(c);
        ptn = bib.begin;
        while (1)
        {
            int tmp;
            cin >> tmp;
            ptn->val = tmp;
            if (cin.get() == '\n')
                break;
            bigintnode *pt = new bigintnode;
            ptn->next = pt;
            bia.figure += 3;
        }
        bib.figure += ptn->val / 10;

        if (ch == '+')
        {
            if (bia.symbol == bib.symbol)
            {
                if (bia.figure > bib.figure)
                    pprint(adda(bia, bib));
                else
                    pprint(adda(bib, bia));
            }
            else
                ch = '-';
        }
        if (ch == '-')
        {
        }
    }
    return 0;
}
