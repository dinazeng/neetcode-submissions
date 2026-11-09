class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int ATLANTIC = 0;
        int PACIFIC = 1;

        set<pair<int, int>> atlantic;
        set<pair<int, int>> pacific;

        queue<pair<pair<int, int>, int>> q;

        for (int r = 0; r < rows; r++) {
            atlantic.insert({r, cols - 1});
            pacific.insert({r, 0});

            q.push({{r, cols - 1}, ATLANTIC});
            q.push({{r, 0}, PACIFIC});
        }

        for (int c = 0; c < cols; c++) {
            atlantic.insert({rows - 1, c});
            pacific.insert({0, c});

            q.push({{rows - 1, c}, ATLANTIC});
            q.push({{0, c}, PACIFIC});
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int r = front.first.first;
            int c = front.first.second;
            int o = front.second;

            for (const auto& d : dirs) {
                int nr = r + d.first;
                int nc = c + d.second;

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (heights[nr][nc] < heights[r][c]) continue;

                if (o == ATLANTIC) {
                    if (atlantic.contains({nr, nc})) continue;

                    atlantic.insert({nr, nc});
                } else {
                    if (pacific.contains({nr, nc})) continue;

                    pacific.insert({nr, nc});
                }

                q.push({{nr, nc}, o});
            }

        }

        vector<vector<int>> sol;

        for (auto& p : atlantic) {
            if (pacific.contains(p)) {
                sol.push_back({p.first, p.second});
            }
        }
        
        return sol;
    }
};
