class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIsland = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    visited[row][col] = true;
                    numIsland++;

                    stack<pair<int, int>> s;
                    s.push({row, col});
                    
                    while (!s.empty()) {
                        int r = s.top().first;
                        int c = s.top().second;

                        s.pop();

                        if (r + 1 < m && !visited[r + 1][c] && grid[r + 1][c] == '1') {
                            visited[r + 1][c] = true;
                            s.push({r + 1, c});
                        }

                        if (r > 0 && !visited[r - 1][c] && grid[r - 1][c] == '1') {
                            visited[r - 1][c] = true;
                            s.push({r - 1, c});
                        }

                        if (c + 1 < n && !visited[r][c + 1] && grid[r][c + 1] == '1') {
                            visited[r][c + 1] = true;
                            s.push({r, c + 1});
                        }

                        if (c > 0 && !visited[r][c - 1] && grid[r][c - 1] == '1') {
                            visited[r][c - 1] = true;
                            s.push({r, c - 1});
                        }
                    }
                }
            }
        }


        return numIsland;
    }
};
