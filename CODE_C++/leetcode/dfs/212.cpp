//前缀树储存words
//dfs遍历board

struct TrieNode
{
    string word;
    unordered_map<char, TrieNode *> Children;
    TrieNode() { this->word = ""; }
};

void insertTrieNode(TrieNode *root, const string &word)
{
    TrieNode *node = root;
    for (auto ch : word)
    {
        if (!node->Children.count(ch))
            node->Children[ch] = new TrieNode();
        node = node->Children[ch];
    }
    node->word = word;
}

class Solution
{
public:
    int direc[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<char>> &board, TrieNode *root, int x, int y, set<string> &res)
    {
        char ch = board[x][y];
        if (!root->Children.count(ch))
        {
            return false;
        }
        root = root->Children[ch];
        if (root->word.size() > 0)
            res.insert(root->word);
        board[x][y] = '#';
        for (int i = 0; i < 4; i++)
        {
            int newx = x + direc[i][0];
            int newy = y + direc[i][1];
            if (newx >= 0 && newx <= board.size() && newy >= 0 && newy <= board[0].size() && board[newx][newy] != '#')
                dfs(board, root, newx, newy, res);
        }
        board[x][y] = ch;
        return true;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        vector<string> ans;
        set<string> res;
        for (auto &word : words)
            insertTrieNode(root, word);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, root, i, j, res);
        for (auto &it : res)
            ans.emplace_back(it);
        return ans;
    }
};