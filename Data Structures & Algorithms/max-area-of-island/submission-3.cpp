class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0 ; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    max_area = max(dfs(r, c, grid, rows, cols), max_area);
                }
            }
        }
        
        return max_area;
    }

    int dfs(int row, int col, vector<vector<int>>& grid, int &max_rows, int &max_cols) {
        int size = 1;
        stack<pair<int, int>> st;
        st.push({row, col});

        grid[row][col] = 0;

        while (!st.empty()) {
            auto top = st.top();
            int r = top.first;
            int c = top.second;
            st.pop();

            for (vector<int> &d : directions) {
                int new_row = d[0] + r;
                int new_col = d[1] + c;

                if (new_row < max_rows && new_col < max_cols && 
                    new_row >= 0 && new_col >= 0 &&
                    grid[new_row][new_col] == 1) {

                        grid[new_row][new_col] = 0;
                        st.push({new_row, new_col});
                        size++;
                }
            }
        }

        return size;
    }
};
