class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ROWS;
    int COLS;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        vector<vector<int>> dp (ROWS, vector<int> (COLS, -1));
        
        int max_path = 1;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                dp[i][j] = dfs(matrix, dp, i, j);

                max_path = max(max_path, dp[i][j]);
            }
        }
        
        return max_path;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c) {
        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        dp[r][c] = 1;

        for (const vector<int>& d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nc >= 0 && nc < COLS && nr < ROWS && matrix[r][c] < matrix[nr][nc]) {
                dp[r][c] = max(dp[r][c], 1 + dfs(matrix, dp, nr, nc));
            }
        }

        return dp[r][c];
    }
};
