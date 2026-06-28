class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int fresh_fruit_left = 0;
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> rotten;
        map<pair<int, int>, int> fresh;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) { 
                if (grid[r][c] == 2) {
                    rotten.push({r, c});
                    fresh[{r, c}] = 0;
                } else if (grid[r][c] == 1) {
                    fresh[{r, c}] = -1;
                    fresh_fruit_left++;
                }
            }
        }

        while (!rotten.empty()) {
            pair <int, int> r = rotten.front();
            rotten.pop();

            int row = r.first;
            int col = r.second;

            vector<pair<int, int>> directions = {{r.first, r.second - 1}, 
                                                 {r.first, r.second + 1}, 
                                                 {r.first - 1, r.second}, 
                                                 {r.first + 1, r.second}};

            for (pair <int, int> d : directions) {
                if (fresh.contains(d) && fresh[d] == -1) {
                    fresh[d] = fresh[r] + 1;
                    rotten.push(d);
                    fresh_fruit_left--;

                    minutes = max (minutes, fresh[d]);
                }
            }
        }

        return fresh_fruit_left == 0 ? minutes : -1;
    }
};
