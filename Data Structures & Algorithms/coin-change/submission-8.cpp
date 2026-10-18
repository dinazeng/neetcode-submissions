class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<int> dp (amount + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < amount; i++) {
            if (dp[i] != -1) {
                for (int j = 0; j < size; j++) {
                    if (amount - i - coins[j] >= 0) {
                        if (dp[i + coins[j]] == -1) {
                            dp[i + coins[j]] = dp[i] + 1;
                        } else {
                            dp[i + coins[j]] = min (dp[i] + 1,  dp[i + coins[j]]);
                        }
                    }
                }
            }
        }



        return dp[amount];
    }
};
