/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    int ans;
    void maxdd(Node *root, int n)
    {
        if (root == nullptr)
        {
            ans = max(ans, n);
            return;
        }
        int len = root->children.size();
        if (len == 0)
        {
            ans = max(ans, n + 1);
            return;
        }
        for (int i = 0; i < len; i++)
        {
            maxdd(root->children[i], n + 1);
        }
        return;
    }
    int maxDepth(Node *root)
    {
        if (root == nullptr)
            return 0;
        maxdd(root, 0);
        return ans;
    }
};