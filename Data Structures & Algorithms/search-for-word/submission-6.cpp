class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row_count = board.size();
        int col_count = board[0].size();

        int index = 0;
        
        for (int i = 0; i < row_count; i++) {
            for (int j = 0; j < col_count; j++) {
                if (dfs(board, word, i, j, 0)) return true;
           }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int r, int c,  int idx) {
        if (idx == word.length()) {
            return true;
        }

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
            return false;
        }

        if (board[r][c] != word[idx]) return false;
        
        board[r][c] = '*';

        bool res = (dfs(board, word, r + 1, c, idx + 1) ||
                    dfs(board, word, r - 1, c, idx + 1) ||
                    dfs(board, word, r, c + 1, idx + 1) ||
                    dfs(board, word, r, c- 1, idx + 1));

        board[r][c] = word[idx];

        return res;
    }
};
