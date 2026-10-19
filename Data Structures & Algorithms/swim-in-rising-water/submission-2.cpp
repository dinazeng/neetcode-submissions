class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        min_heap.push({grid[0][0], 0, 0});
        visit.insert({0, 0});

        while (!min_heap.empty()) {
            auto top = min_heap.top();
            min_heap.pop();

            int t = top[0];
            int r = top[1];
            int c = top[2];

            if (r == n - 1 && c == n - 1) {
                return t;
            }

            for (const auto & d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nc < 0 || nr == n ||
                    nc == n || visit.count({nr, nc})) {
                    continue;
                }

                visit.insert({nr, nc});
                min_heap.push({max(grid[nr][nc], t), nr, nc});
            }
        }

        return n*n;
    }
};
