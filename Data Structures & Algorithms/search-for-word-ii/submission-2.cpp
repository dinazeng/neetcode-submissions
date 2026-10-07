class Solution {
public:
    struct TrieNode {
        string str;
        vector<TrieNode*> children;

        TrieNode() {
            str = "";
            children = vector<TrieNode*>(26, nullptr);
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<string> foundWords;

        TrieNode* head = new TrieNode();

        for (string word : words) {
            int length = word.size();
            TrieNode* index = head;
            for (int i = 0; i < length; i++) {
                int char_val = word[i] - 'a';

                if (index->children[char_val] == nullptr) {
                    index->children[char_val] = new TrieNode();
                }
               
                index = index->children[char_val];
            }
            index->str = word;
        }

        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dfs(board, r, c, head,foundWords);
            }
        }
        return foundWords;
    }

    void dfs (vector<vector<char>> &board, int r, int c, TrieNode* &head, vector<string> &res) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return;

        char ch = board[r][c];
        if (ch == '#') return;

        TrieNode* node = head->children[ch - 'a'];
        if (!node) return;   

        if (!node->str.empty()) {
            res.push_back(node->str);
            node->str.clear();                      // avoid duplicates
        }

        board[r][c] = '#';                           // mark used on this path
        dfs(board, r + 1, c, node, res);
        dfs(board, r - 1, c, node, res);
        dfs(board, r, c + 1, node, res);
        dfs(board, r, c - 1, node, res);
        board[r][c] = ch;  
    }
};
