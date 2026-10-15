class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int new_row = row + directions[i][0];
                int new_col = col + directions[i][1];

                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
                    if (grid[new_row][new_col] == 2147483647) {
                        grid[new_row][new_col] = grid[row][col] + 1;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
    }
};
