class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> sol (m, vector<int> (n));

        sol[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            sol[i][0] = grid[i][0] + sol[i - 1][0];
        }

        for (int j = 1; j < n; j++) {
            sol[0][j] = grid[0][j] + sol[0][j - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sol[i][j] = grid[i][j];

                sol[i][j] += min (sol[i - 1][j], sol[i][j - 1]);
            }
        }

        return sol[m - 1][n - 1];
    }
};