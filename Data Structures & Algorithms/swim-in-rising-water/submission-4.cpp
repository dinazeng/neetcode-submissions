class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        set<pair<int, int>> visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
        visited.insert({0, 0});
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int dist = top[0];
            int row = top[1];
            int col = top[2];

            if (row == m - 1 && col == m - 1) {
                return dist;
            }

            for (int i = 0; i < 4; i++) {
                int new_row = directions[i][0] + row;
                int new_col = directions[i][1] + col;
                
                if (new_row >= m || new_row < 0 || new_col >= m || new_col < 0 ||           
                    visited.contains({new_row, new_col})) continue;
                
                visited.insert({new_row, new_col});
                pq.push({max(dist, grid[new_row][new_col]), new_row, new_col});
            }
        }

        return INT_MAX;
    }
};
