class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int r = 0 ; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int size = 1;
                    stack<pair<int, int>> st;
                    st.push({r, c});

                    grid[r][c] = 0;

                    while (!st.empty()) {
                        auto top = st.top();
                        int r_curr = top.first;
                        int c_curr = top.second;
                        st.pop();

                        for (vector<int> &d : directions) {
                            int new_row = d[0] + r_curr;
                            int new_col = d[1] + c_curr;

                            if (new_row < rows && new_col < cols && 
                                new_row >= 0 && new_col >= 0 &&
                                grid[new_row][new_col] == 1) {

                                    grid[new_row][new_col] = 0;
                                    st.push({new_row, new_col});
                                    size++;
                            }
                        }
                    }

                    max_area = max(max_area, size);
                }
            }
        }
        
        return max_area;
    }
};
