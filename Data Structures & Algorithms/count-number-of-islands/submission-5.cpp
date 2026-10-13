class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIsland = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1') {
                    numIsland++;
                    grid[row][col] = '0';

                    stack<pair<int, int>> s;

                    s.push({row, col});
                    
                    while (!s.empty()) {
                        int r = s.top().first;
                        int c = s.top().second;

                        s.pop();

                        for (auto &d : directions) {
                            int new_row = r + d[0];
                            int new_col = c + d[1];

                            if (new_row < m && new_row >= 0 &&
                                new_col < n && new_col >= 0 && 
                                grid[new_row][new_col] == '1') {

                                grid[new_row][new_col] = '0';
                                s.push({new_row, new_col});
                            }
                        }
                    }
                }
            }
        }


        return numIsland;
    }
};
