class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int size = coins.size();
        vector<vector<int>> grid (size + 1, vector<int>(amount + 1, 0));

        for (int c = 0; c <= size; c++) {
            grid[c][0] = 1;
        }

        for (int i = size - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                if (j >= coins[i]) {
                    grid[i][j] = grid[i + 1][j] + grid[i][j - coins[i]];
                }
            }
        }


        return grid[0][amount];
    }
};
