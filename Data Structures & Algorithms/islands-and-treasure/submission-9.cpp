class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int INF = 2147483647;

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            int r = front.first;
            int c = front.second;

            q.pop();

            for (const vector<int> &d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL && grid[nr][nc] == INF) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc}); 
                }
            }
        }
    }
};
