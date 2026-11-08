class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int max_path = top.first;
            int row = top.second.first;
            int col = top.second.second;

            for (const vector<int>& d : dir) {
                int next_row = row + d[0];
                int next_col = col + d[1];

                if (next_row < rows && next_row >= 0 && next_col < cols && next_col >= 0) {
                    int next_max = max(max_path, grid[next_row][next_col]);
                    if (dist[next_row][next_col] > next_max) {
                        dist[next_row][next_col] = next_max;
                        pq.push({next_max, {next_row, next_col}});
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }
};
