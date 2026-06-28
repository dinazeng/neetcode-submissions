class Trie {
public:
    Trie* child[26] = {};
    bool endOfWord = false;
};

class WordDictionary {
    Trie* root = new Trie();
public:
    void addWord(const string& word) {
        Trie* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->child[i]) node->child[i] = new Trie();
            node = node->child[i];
        }
        node->endOfWord = true;
    }

    bool search(const string& word) {
        vector<Trie*> level = {root};
        for (char c : word) {
            if (level.empty()) return false;
            vector<Trie*> next;
            for (Trie* node : level) {
                if (c == '.') {
                    for (Trie* ch : node->child)
                        if (ch) next.push_back(ch);
                } else {
                    Trie* ch = node->child[c - 'a'];
                    if (ch) next.push_back(ch);
                }
            }
            level = move(next);
        }
        for (Trie* node : level)
            if (node->endOfWord) return true;
        return false;
    }
};