class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            vector<bool> seen_row(9, false);

            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';
                    if (seen_row[num]) {
                        return false;
                    } 

                    seen_row[num] = true;
                }
            }
        }

        for (int c = 0; c < 9; c++) {
           vector<bool> seen_col(9, false);

            for (int r = 0; r < 9; r++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';
                    if (seen_col[num]) {
                        return false;
                    }

                    seen_col[num] = true;
                }
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                vector<bool> seen_square(9, false);

                for (int r = row; r < row + 3; r++) {
                    for (int c = col; c < col + 3; c++) {
                        if (board[r][c] != '.') {
                            int num = board[r][c] - '1';
                            if (seen_square[num]) {
                                return false;
                            }

                            seen_square[num] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};