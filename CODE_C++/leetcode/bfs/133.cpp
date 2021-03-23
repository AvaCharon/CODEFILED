/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        Node *clonode = new (Node);
        clonode = node;
        queue<Node *> q;
        unordered_set<Node *> us;
        q.push(node);
        us.insert(node);
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                Node *tmp = q.front();
                q.pop();
                int lenn = tmp->neighbors.size();
                Node *curr = new (Node);
                curr = tmp;
                for (int j = 0; j < lenn; j++)
                {
                    if (us.insert(tmp->neighbors[j]).second)
                        q.push(tmp->neighbors[j]);
                    curr->neighbors.push_back(tmp->neighbors[j]);
                }
            }
        }
        return clonode;
    }
};

//

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return node;
        }

        unordered_map<Node *, Node *> visited;

        // 将题目给定的节点添加到队列
        queue<Node *> Q;
        Q.push(node);
        // 克隆第一个节点并存储到哈希表中
        visited[node] = new Node(node->val);

        // 广度优先搜索
        while (!Q.empty())
        {
            // 取出队列的头节点
            auto n = Q.front();
            Q.pop();
            // 遍历该节点的邻居
            for (auto &neighbor : n->neighbors)
            {
                if (visited.find(neighbor) == visited.end())
                {
                    // 如果没有被访问过，就克隆并存储在哈希表中
                    visited[neighbor] = new Node(neighbor->val);
                    // 将邻居节点加入队列中
                    Q.push(neighbor);
                }
                // 更新当前节点的邻居列表
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};
