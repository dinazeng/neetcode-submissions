class Solution {
public:
    int row_count;
    int col_count;
    bool exist(vector<vector<char>>& board, string word) {
        row_count = board.size();
        col_count = board[0].size();

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

        if (r < 0 || r >= row_count || c < 0 || c >= col_count) {
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
