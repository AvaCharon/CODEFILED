class Trie
{
private:
    vector<Trie *> children;
    bool isEnd;

    Trie *searchprefix(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            int c = ch - 'a';
            if (!node->children[c])
                return nullptr;
            node = node->children[c];
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false){};

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            int c = ch - 'a';
            if (!node->children[c])
                node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *node = searchprefix(word);
        if (node == nullptr)
            return false;
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *node = searchprefix(prefix);
        if (node == nullptr || node->children.size() == 0)
            return false;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */