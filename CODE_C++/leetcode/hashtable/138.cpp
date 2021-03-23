/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        unordered_set<Node *> us;
        Node *pt = head;
        Node *ans = new Node(pt->val);
        for (;;)
        {
            if (!us.insert(pt).second)
                break;
            if (pt->next == nullptr)
                break;
            pt = pt->next;
        }
        pt = head;
        Node *pr = head->random;
        for (;;)
        {
            if (us.insert(pr).second)
            {
                ans->random = pr;
            }
            else
                ans->random = nullptr;
            ans->val = pt->val;
            if (pt->next == nullptr)
                break;
            pt = pt->next;
            pr = pt->random;
            ans->next = new Node(pt->val);
            ans = ans->next;
        }
        return ans;
    }
};

//别人写的

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;
        mp[nullptr] = nullptr;
        auto p = head;
        while (p)
        {
            mp[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while (p)
        {
            mp[p]->next = mp[p->next];
            p = p->next;
        }
        p = head;
        while (p)
        {
            mp[p]->random = mp[p->random];
            p = p->next;
        }
        return mp[head];
    }
};