class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int fresh_fruit = 0;

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }

                if (grid[r][c] == 1) {
                    fresh_fruit++;
                }
            }
        }

        int time = 0;

        while (!q.empty() && fresh_fruit > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto front = q.front();
                int r = front.first;
                int c = front.second;

                q.pop();

                for (const vector<int> &d : directions) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL && grid[nr][nc] == 1) {
                        fresh_fruit--;
                        grid[nr][nc] = 2;
                        q.push({nr, nc}); 
                    }
                }
            }

            time++;
        }

        return fresh_fruit == 0 ? time : -1;
    }
};
