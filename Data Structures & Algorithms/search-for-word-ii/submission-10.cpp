class Solution {
public:
    int ROWS;
    int COLS;

    struct Trie {
        Trie* children[26];
        string str;
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> sol;
        Trie* head = new Trie();
        ROWS = board.size();
        COLS = board[0].size();

        for (string &word : words) {
            Trie* index = head;
            for (char c : word) {
                int char_val = c - 'a';
                if (!index->children[char_val]) {
                    index->children[char_val] = new Trie();
                }

                index = index->children[char_val];
            }

            index->str = word;
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(board, head, sol, r, c);
            }
        }

        return sol;
    }

    void dfs(vector<vector<char>>& board, Trie* &index, vector<string>& sol, int row, int col) {
        if (row >= ROWS || row < 0 || col >= COLS || col < 0) return;

        char loc = board[row][col];
        if (loc == '*') return;

        Trie* node = index->children[loc - 'a'];

        if (!node) return;

        if (node->str != "") {
            sol.push_back(node->str);
            node->str.clear();
        }

        board[row][col] = '*';

        
        dfs(board, node, sol, row + 1, col);
        dfs(board, node, sol, row - 1, col);
        dfs(board, node, sol, row, col + 1);
        dfs(board, node, sol, row, col - 1);

        board[row][col] = loc;
    }
};
