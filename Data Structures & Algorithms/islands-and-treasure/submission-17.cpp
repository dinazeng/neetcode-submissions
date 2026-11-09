class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int r = front.first;
            int c = front.second;

            for (const auto& d : dirs) {
                int nr = r + d.first;
                int nc = c + d.second;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (grid[nr][nc] == INT_MAX) {
                        int nd = grid[r][c] + 1;
                        grid[nr][nc] = nd;

                        q.push({nr, nc});
                    }
                }
            }
        }
    }
};
