class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int fresh_fruit = 0;
        int time = 0;

        queue<pair<int, int>> q;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    fresh_fruit++;
                } else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();

                for (const auto& d : dirs) {
                    int nr = front.first + d.first;
                    int nc = front.second + d.second;

                    if (nr < rows && nr >= 0 && nc < cols && nc >= 0) {
                        if (grid[nr][nc] == 1) {
                            fresh_fruit--;
                            grid[nr][nc] = 2;

                            q.push({nr, nc});
                        }
                    }
                }
            }

            if (!q.empty()) {
                time++;
            }
        }

        return fresh_fruit == 0? time : -1;
    }
};
