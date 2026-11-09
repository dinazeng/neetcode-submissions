class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

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

            for (int i = 0; i < 4; i++) {
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];
                
                if (nr < rows && nr >= 0 && nc < cols && nc >= 0) {
                    int next_max = max(max_path, grid[nr][nc]);
                    if (dist[nr][nc] > next_max) {
                        dist[nr][nc] = next_max;
                        pq.push({next_max, {nr, nc}});
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }
};
