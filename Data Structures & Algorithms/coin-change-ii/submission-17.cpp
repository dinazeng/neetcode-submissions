class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;

        int size = coins.size();

        vector<vector<int>> dp (amount + 1, vector<int>(size + 1));

        for (int i = 0; i <= size; i++) {
            dp[0][i] = 1;
        }

        for (int j = 1; j <= amount; j++) {
            for (int k = 1; k <= size; k++) {
                dp[j][k] = dp[j][k - 1];

                if (coins[k - 1] <= j) {
                    dp[j][k] += dp[j - coins[k - 1]][k];
                }
            }
        }

        return dp[amount][size];
    } 
};
