class Solution {
public:
    struct Trie {
        string str;
        Trie* children[26];

        Trie() {
            str = "";
            for (Trie* &t : children) {
                t = nullptr;
            }
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<string> sol;
        Trie* head = new Trie();
        int row_max = board.size();
        int col_max = board[0].size();
       
        for (string word : words) {
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

        for (int r = 0; r < row_max; r++) {
            for (int c = 0; c < col_max; c++) {
                dfs(sol, board, r, c, head);
            }
        }

        return sol;
    }

    void dfs(vector<string> &sol, vector<vector<char>> &board, int row, int col, Trie* &head) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return;
        
        char process_c = board[row][col];
        if (process_c == '*') return;

        Trie* node = head->children[process_c - 'a'];
        if (!node) return;

        if (node->str != "") {
            sol.push_back(node->str);
            node->str.clear();
        }

        board[row][col] = '*';

        dfs(sol, board, row + 1, col, node);
        dfs(sol, board, row - 1, col, node);
        dfs(sol, board, row, col + 1, node);
        dfs(sol, board, row, col - 1, node);
        
        board[row][col] = process_c;
    }
};
