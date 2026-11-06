class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<int>> dp (amount + 1, vector<int>(size + 1));

        for (int i = 0; i <= size; i++) {
            dp[0][i] = 1;
        }

        for (int i = 0; i <= amount; i++) {
            for (int j = 1; j <= size; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i >= coins[j - 1]) {
                    dp[i][j] += dp[i - coins[j - 1]][j];
                }
            }
        }

        return dp[amount][size];
    }
};
