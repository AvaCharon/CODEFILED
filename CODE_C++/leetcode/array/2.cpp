/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans1, *ans2;
        ans1 = l1, ans2 = l2;
        while (l1 && l2)
        {
            int ans = l1->val + l2->val;
            if (ans >= 10)
            {
                if (l1->next)
                    l1->next->val++;
                else
                {
                    ListNode *n = new ListNode();
                    l1->next = n;
                    n->val = 1;
                }
                l1->val = ans - 10;
            }
            else
                l1->val = ans;
            l1 = l1->next, l2 = l2->next;
        }
        if (l1)
        {
            while (l1)
            {
                if (l1->val >= 10)
                {
                    if (l1->next)
                        l1->next->val++;
                    else
                    {
                        ListNode *n = new ListNode();
                        l1->next = n;
                        n->val = 1;
                    }
                    l1->val -= 10;
                }
                l1 = l1->next;
            }
            return ans1;
        }
        if (l2)
        {
            while (l2)
            {
                if (l2->val >= 10)
                {
                    if (l2->next)
                        l2->next->val++;
                    else
                    {
                        ListNode *n = new ListNode();
                        l2->next = n;
                        n->val = 1;
                    }
                    l2->val -= 10;
                }
                l2 = l2->next;
            }
            l2 = ans2;
            while (ans1)
            {
                ans2->val = ans1->val;
                ans2 = ans2->next, ans1 = ans1->next;
            }
            return l2;
        }
        return ans1;
    }
};