class Solution {
public:
    int ROWS;
    int COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
               if (dfs(board, word, 0, r, c)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int index, int r, int c) {
        if (index == word.size()) {
            return true;
        }

        if (r >= ROWS || c >= COLS || r < 0 || c < 0) {
            return false;
        }

        if (board[r][c] != word[index]) {
            return false;
        }

        board[r][c] = '*';

        bool res =  dfs(board, word, index + 1, r + 1, c) || 
                    dfs(board, word, index + 1, r - 1, c) ||
                    dfs(board, word, index + 1, r, c + 1) ||
                    dfs(board, word, index + 1, r, c - 1);

        board[r][c] = word[index];

        return res;
    }
};
