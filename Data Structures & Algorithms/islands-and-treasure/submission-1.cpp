class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair <int, int>> q;
        int row = grid.size();
        int col = grid[0].size();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        while (!q.empty()) {
            int qRow = q.front().first;
            int qCol = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = qRow + directions[i].first;
                int c = qCol + directions[i].second;

                if (r >= 0 && r < row && c >= 0 && c < col) {
                    if (grid[r][c] == 2147483647) {
                        grid[r][c] = grid[qRow][qCol] + 1;
                        q.push({r, c});
                    }
                }
            }
        }
    }
};
