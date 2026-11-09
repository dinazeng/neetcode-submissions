class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<vector<int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int r = front[0];
            int c = front[1];
            int dist = front[2];

            for (const vector<int>& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (grid[nr][nc] == INT_MAX) {
                        grid[nr][nc] = dist + 1;

                        q.push({nr, nc, dist + 1});
                    }
                }
            }
        }
    }
};
