class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIsland = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1') {
                    numIsland++;

                    stack<pair<int, int>> s;
                    s.push({row, col});
                    
                    while (!s.empty()) {
                        int r = s.top().first;
                        int c = s.top().second;

                        grid[r][c] = '0';

                        s.pop();

                        if (r + 1 < m && grid[r + 1][c] == '1') {
                            s.push({r + 1, c});
                        }

                        if (r > 0 && grid[r - 1][c] == '1') {
                            s.push({r - 1, c});
                        }

                        if (c + 1 < n && grid[r][c + 1] == '1') {
                            s.push({r, c + 1});
                        }

                        if (c > 0 && grid[r][c - 1] == '1') {
                            s.push({r, c - 1});
                        }
                    }
                }
            }
        }


        return numIsland;
    }
};
