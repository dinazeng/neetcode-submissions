class Solution {
public:
    int ROWS;
    int COLS;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int max_area = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    int area = 0;
                    dfs(grid, r, c, area);

                    max_area = max(area, max_area);
                }
            }
        }

        return max_area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c, int& area) {
        if (r >= ROWS || r < 0 || c >= COLS || c < 0) {
            return area;
        }

        if (grid[r][c] == 0) {
            return area;
        }

        grid[r][c] = 0;
        area++;
        
        for (const vector<int>& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            dfs(grid, nr, nc, area);
        }

        return area;
    }
};
