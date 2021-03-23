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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * pl=head;
        int len=1;
        while(pl->next!=nullptr)
        {
            pl=pl->next;
            len++;
        }
        if(len==n)return head->next;
        pl=head;
        for(int i=1;i<len-n;i++)
        {
            pl=pl->next;
        }
        ListNode * temp=pl->next;
        pl->next=temp->next;
        return head;
    }
};