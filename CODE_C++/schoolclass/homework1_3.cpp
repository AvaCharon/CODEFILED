class solution
{
public:
    ListNode *fun1(ListNode *L, int min, int max)
    {
        ListNode *head = new ListNode();
        ListNode *pre = head;
        head->next = L;
        while (L)
        {
            if (L->val < min)
            {
                if (L->val >= max)
                    break; //升序链表，后面元素不用检验了
                pre->next = L->next;
                free(L);
            }
            else
                pre = pre->next;
            L = pre->next;
        }
        return head->next;
    }
    int fun2(int *a, int *b, int len)
    {
        int half = len / 2;
        if (a[half] == b[half])
            return a[half];
        else if (a[half] > b[half])
            fun2(a, b + half, half);
        else
            fun2(a + half, b, half);
    }
    ListNode *fun3(ListNode *head)
    {
        unordered_set<int> us;
        ListNode *node = head->next;
        ListNode *pre = head;
        while (node)
        {
            if (!us.insert(abs(node->data)))
            {
                pre->next = node->next;
                free(node);
            }
            else
                pre = pre->next;
            node = pre->next;
        }
        return head;
    }
    ListNode *LocateNode(ListNode *L, int x)
    {
        ListNode *ans = L.find(x);
        if (!ans->pred == L)
            return L;
        ListNode *prev = ans->prev = d;
        ans.freq++;
        while (prev->pred != L && ans->freq > prev->freq)
        {
            prev = prev->pred;
        }
        if (!prev->pred)
        {
            ans->pred->next = ans->next;
            ans->next = L->next;
            L->next = ans;
        }
        else
        {
            ans->pred->next = ans->next;
            ans->next = prev->next;
            prev->next = ans;
        }
        return L;
    }
    int *fun51(int *a, int n) //非递归
    {
        int ans[2]; //第一位为最大值，第二位为最小值
        ans[0] = ans[1] = a[0];
        for (int i = 1; i < n; i++)
        {
            if (ans[0] < a[i])
                ans[0] = a[i];
            if (ans[1] > a[i])
                ans[1] = a[i];
        }
        return ans;
    }
    int *fun52(int *a, int left, int right, int n)
    {
        int ans[2];
        if (left == right)
            ans[0] = ans[1] = a[left];
        else if (left + 1 == right)
        {
            ans[0] = a[left] > a[right] ? a[left] : a[right];
            ans[1] = a[left] < a[right] ? a[left] : a[right];
        }
        else
        {
            int *p = fun52(a, left, right / 2, n / 2);
            int *q = fun52(a, right / 2, left + n - 1, n / 2);
            ans[0] = p[0] > q[0] ? p[0] : q[0];
            ans[1] = p[1] < q[1] ? p[1] : q[1];
        }
        return ans;
    }
}