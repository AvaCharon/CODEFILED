/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> ans;
        int j = -1;
        while (head != nullptr)
        {
            ans.push_back(head->val);
            head = head->next;
            j++;
        }
        for (int i = 0; i < j; i++, j--)
        {
            if (ans[i] != ans[j])
                return false;
        }
        return true;
    }
};