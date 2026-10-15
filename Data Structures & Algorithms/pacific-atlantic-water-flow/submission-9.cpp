class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<set<vector<int>>> oceans(2);
        queue<vector<int>> q;

        vector<vector<int>> solution;

        int rows = heights.size();
        int cols = heights[0].size();

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int r = 0; r < rows; r++) {
            oceans[1].insert({r, 0});
            oceans[0].insert({r, cols - 1});
            q.push({r, cols - 1, 0});
            q.push({r, 0, 1});
        }

        for (int c = 0; c < cols; c++) {
            oceans[1].insert({0, c});
            oceans[0].insert({rows - 1, c});
            q.push({rows - 1, c, 0});
            q.push({0, c, 1});
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int row = front[0];
            int col = front[1];
            int ocean = front[2];

            for (int i = 0; i < 4; i++) {
                int new_row = row + directions[i][0];
                int new_col = col + directions[i][1];

                if (new_row < rows && new_row >= 0 && new_col < cols && new_col >= 0) {
                    if (heights[new_row][new_col] >= heights[row][col]) {
                        if (!oceans[ocean].contains({new_row, new_col})) {
                            oceans[ocean].insert({new_row, new_col});
                            q.push({new_row, new_col, ocean});
                        }
                    }
                }
            }
        }

        for (vector<int> spot : oceans[0]) {
            if (oceans[1].contains(spot)) {
                solution.push_back(spot);
            }
        }

        return solution;
    }
};
