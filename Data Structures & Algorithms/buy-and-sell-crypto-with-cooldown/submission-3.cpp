class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<pair<int, int>, int> dp;
        return dfs(prices, dp, 0, true);
    }

    int dfs(vector<int> &prices, map<pair<int, int>, int> &dp, int index, bool buying) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp.contains({index, buying})) {
            return dp[{index, buying}];
        }

        int cooldown = dfs(prices, dp, index + 1, buying);
        if (buying) {
            int buy = dfs(prices, dp, index + 1, !buying) - prices[index];
            dp[{index, buying}] = max(buy, cooldown);
        } else {
            int sell = dfs(prices, dp, index + 2, !buying) + prices[index];
            dp[{index, buying}] = max(cooldown, sell);
        }

        return dp[{index, buying}];
    }
};
