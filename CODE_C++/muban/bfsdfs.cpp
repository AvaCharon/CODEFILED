//BFS
void BFS_Search(ListNode* root)
{
    if(!root) return;
 
    queue<ListNode*> q;
    visit(root);
    root.visited = true;
    q.push(root);
 
    while(!q.empty())
    {
        ListNode* node = q.pop_front();
        foreach(ListNode* pChild in node->adjacent)
            if(!pChild->visited)
            {
                visit(pChild);
                pChild->visited = true;
                q.push_back(pChild);
            }
    }
}