class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < amount; i++) {
            if (dp[i] == INT_MAX) continue;

            for (const auto& c : coins) {
                if (c > amount - i) continue; 
                dp[i + c] = min(dp[i + c], dp[i] + 1);
            }
        }

        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
