class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited (m, vector<int>(n, false));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!visited[r][c] && grid[r][c] == 1) {
                    stack<pair<int, int>> q;
                    q.push({r, c});
                    int area = 0;
                    visited[r][c] = true;

                    while (!q.empty()) {
                        int row = q.top().first;
                        int col = q.top().second;

                        q.pop();

                        area++;

                        if (row - 1 > 0 && !visited[row - 1][col]) {
                            if (grid[row - 1][col] == 1) {
                                q.push({row - 1, col}); 
                                visited[row - 1][col] = true;
                            }
                        }

                        if (row + 1 < m && !visited[row + 1][col]) {
                            if (grid[row + 1][col] == 1) {
                                q.push({row + 1, col}); 
                                visited[row + 1][col] = true;
                            }
                        }

                        if (col - 1 > 0 && !visited[row][col - 1]) {
                            if (grid[row][col - 1] == 1) {
                                q.push({row, col - 1}); 
                                visited[row][col - 1] = true;
                            }
                        } 

                        if (col + 1 < n && !visited[row][col + 1]) {
                           if (grid[row][col + 1] == 1) {
                                q.push({row, col + 1}); 
                                visited[row][col + 1] = true;
                            }
                        }
                       
                    }
                    
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};
