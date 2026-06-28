class TreeNode {
public:
    TreeNode* children[26];
    bool endOfWord;

    TreeNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }

        endOfWord = false;
    }
};

class PrefixTree {
public:
    TreeNode* root;

    PrefixTree() { 
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TreeNode();
            }

            cur = cur->children[i];
        }

        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TreeNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }

            cur = cur->children[i];
        }

        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }

            cur = cur->children[i];
        }

        return true;
    }

};
