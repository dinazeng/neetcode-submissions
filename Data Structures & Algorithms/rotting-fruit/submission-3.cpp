class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int fresh_fruit_left = 0;
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> rotten;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) { 
                if (grid[r][c] == 2) {
                    rotten.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh_fruit_left++;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, -1}, 
                                                 {0, 1}, 
                                                 {-1, 0}, 
                                                 {1, 0}};

        while (fresh_fruit_left > 0 && !rotten.empty()) {
            int length = rotten.size();
            for (int i = 0; i < length; i++) {
                pair <int, int> r = rotten.front();
                rotten.pop();

                int row_now = r.first;
                int col_now = r.second;

                for (pair <int, int> &p : directions) {
                    int r_next = row_now + p.first;
                    int c_next = col_now + p.second;
                    if (r_next >= 0 && r_next < row && c_next >= 0 && c_next < col && grid[r_next][c_next] == 1) {
                        grid[r_next][c_next] = 2;
                        rotten.push({r_next, c_next});
                        fresh_fruit_left--;
                    }
                }
            }
            minutes++;
        }
        
        return fresh_fruit_left == 0 ? minutes : -1;
    }
};
