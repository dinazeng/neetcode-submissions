class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row_length = matrix.size();
        int col_length = matrix[0].size();

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> indegree(row_length, vector<int>(col_length, 0));
        
        for (int r = 0; r < row_length; r++) {
            for (int c = 0; c < col_length; c++) {
                for (vector<int> d : directions) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr < row_length && nr >= 0 && nc < col_length && nc >= 0) {
                        if (matrix[nr][nc] < matrix[r][c]) {
                            indegree[r][c]++;
                        }
                    }
                }
            }
        }

        queue<vector<int>> q;
        for (int r = 0; r < row_length; r++) {
            for (int c = 0; c < col_length; c++) {
                if (indegree[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int LIS = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> front = q.front();
                q.pop();

                int r = front[0];
                int c = front[1];
                for (vector<int> d : directions) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr < row_length && nr >= 0 && nc < col_length && nc >= 0) {
                        if (matrix[nr][nc] > matrix[r][c]) {
                            indegree[nr][nc]--;

                            if (indegree[nr][nc] == 0) {
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }

            LIS++;
        }


        return LIS;
    }
};
