class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int ROW;
    int COL;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();

        int max_area = 0;
    
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    int area = 1;
                    dfs(grid, r, c, area);

                    max_area = max(area, max_area);
                }
            }
        }

        return max_area;
    }

     void dfs (vector<vector<int>>& grid, int r, int c, int &area) {
        for (const vector<int> &d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr < ROW && nr >= 0 && nc < COL && nc >= 0 && grid[nr][nc] == 1) {
                grid[nr][nc] = 0;
                area++;
                dfs(grid, nr, nc, area);
            } 
        }
    }
};
