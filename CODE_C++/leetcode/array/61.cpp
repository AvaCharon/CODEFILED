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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        ListNode *fast = head;
        int len = 1;
        while (fast->next)
        {
            len++;
            fast = fast->next;
        }
        k = k % len;
        if (!k)
            return head;
        fast = head;
        for (int i = 0; i < k - 1; i++)
        {
            fast = fast->next;
        }
        ListNode *slow = head;
        ListNode *pre;
        while (fast->next)
        {
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        fast->next = head;
        return slow;
    }
};