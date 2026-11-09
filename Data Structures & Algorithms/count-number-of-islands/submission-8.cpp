class Solution {
public:
    int ROWS;
    int COLS;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int count = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r >= ROWS || r < 0 || c >= COLS || c < 0) {
            return;
        }

        if (grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';
        
        for (const vector<int>& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            dfs(grid, nr, nc);
        }
    }
};
