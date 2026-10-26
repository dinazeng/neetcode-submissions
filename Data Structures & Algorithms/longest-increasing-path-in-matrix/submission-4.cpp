class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row_length = matrix.size();
        int col_length = matrix[0].size();
        vector<vector<int>> dfs_res (row_length, vector<int>(col_length, -1));

        int max_length = 1;
        for (int i = 0; i < row_length; i++) {
            for (int j = 0; j < col_length; j++) {
                max_length = max(max_length, dfs(dfs_res, matrix, i, j));
            }
        }

        return max_length;
    }

    int dfs(vector<vector<int>> &dfs_res, vector<vector<int>>& matrix, int r, int c) {
        if (dfs_res[r][c] != -1) {
            return dfs_res[r][c];
        } 

        int max_length = 1;
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        for (int i = 0; i < 4; i++) {
            int next_row = dir[i][0] + r;
            int next_col = dir[i][1] + c;

            if (next_row < ROWS && next_row >= 0 && next_col < COLS && next_col >= 0 && matrix[r][c] < matrix[next_row][next_col]) {
                max_length = max(dfs(dfs_res, matrix, next_row, next_col) + 1, max_length);
            }
        }

        dfs_res[r][c] = max_length;

        return dfs_res[r][c];
    }
};
