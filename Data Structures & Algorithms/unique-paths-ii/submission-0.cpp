class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> moves (m, vector<int> (n));\

        moves[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    moves[i][j] = 0;
                } else {
                    if (i > 0) {
                        moves[i][j] += moves[i - 1][j];
                    }
                    if (j > 0) {
                        moves[i][j] += moves[i][j - 1];
                    }
                }

            }
        }

        return moves[m - 1][n - 1];
    }
};