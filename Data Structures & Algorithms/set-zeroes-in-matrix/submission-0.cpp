class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        bool rowZero = false;

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;

                    if (i > 0) {
                        matrix[i][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        for (int r = 1; r < row_size; r++) {
            for (int c = 1; c < col_size; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int r = 0; r < row_size; r++) {
                matrix[r][0] = 0;
            }
        }

        if (rowZero) {
            for (int c = 0; c < col_size; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};
