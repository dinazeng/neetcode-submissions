class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int ROW;
    int COL;

    int numIslands(vector<vector<char>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();

        int count = 0;
    
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == '1') {
                    count++;
                    grid[r][c] = '0';
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }

    void dfs (vector<vector<char>>& grid, int &r, int &c) {
        for (const vector<int> &d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr < ROW && nr >= 0 && nc < COL && nc >= 0 && grid[nr][nc] == '1') {
                grid[nr][nc] = '0';
                dfs(grid, nr, nc);
            } 
        }
    }
};
