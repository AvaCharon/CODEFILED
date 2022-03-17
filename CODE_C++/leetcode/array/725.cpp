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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int len = 0;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            curr = curr->next;
            len++;
        }
        int eachlen = len / k, mark = len % k;
        vector<ListNode *> ans(k, nullptr);

        curr = head;
        for (int i = 0; i < k && curr != nullptr; i++)
        {
            ans[i] = curr;
            int currlen = eachlen;
            if (i < mark)
                currlen++;
            for (int j = 1; j < currlen; j++)
                curr = curr->next;

            ListNode *next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return ans;
    }
};