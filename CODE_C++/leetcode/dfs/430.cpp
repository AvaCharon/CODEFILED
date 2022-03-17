/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *dfs(Node *curr)
    {
        Node *last = curr;
        if (curr != nullptr)
        {
            Node *next = curr->next;
            if (curr->child != nullptr)
            {
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
                last = dfs(curr->child);
            }
            if (next != nullptr)
            {
                next->prev = last;
                last->next = next;
                last = dfs(next);
            }
        }
        return last;
    }

    Node *flatten(Node *head)
    {
        dfs(head);
        return head;
    }
};



// 递归
class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *cur = head;
        while (cur)
        {
            if (cur->child)
            {
                flatten(cur->child);
                Node *nxt = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                Node *tail = cur->child;
                while (tail->next)
                    tail = tail->next;
                tail->next = nxt;
                if (nxt)
                {
                    nxt->prev = tail;
                }
                cur->child = nullptr;
                cur = tail;//避免重复递归
            }
            cur = cur->next;
        }
        return head;
    }
};