class Trie {
public:
    bool is_leaf;
    vector<Trie*> children;

    Trie() {
        is_leaf = false;
        children = vector<Trie*> (26);
    }
};

class PrefixTree {
public:
    Trie* head;
    PrefixTree() {
        head = new Trie();
    }
    
    void insert(string word) {
        Trie* index = head;

        for (char c : word) {
            if (!index->children[c - 'a']) {
                Trie* child = new Trie();

                index->children[c - 'a'] = child;
            }

            index = index->children[c - 'a'];
        }

        index->is_leaf = true;
    }
    
    bool search(string word) {
        Trie* index = head;

        for (char c : word) {
            if (!index->children[c - 'a']) {
                return false;
            }

            index = index->children[c - 'a'];
        }

        return index->is_leaf;
    }
    
    bool startsWith(string prefix) {
        Trie* index = head;

        for (char c : prefix) {
            if (!index->children[c - 'a']) {
                return false;
            }

            index = index->children[c - 'a'];
        }

        return true;
    }
};
