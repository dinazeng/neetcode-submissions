class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<pair<int, int>, int> dp;
        return dfs(dp, prices, 0, true);
    }

    int dfs (map<pair<int, int>, int> &dp, vector<int>& prices, int index, bool buying) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp.contains({index, buying})) {
            return dp[{index,buying}];
        }

        int cooldown = dfs(dp, prices, index + 1, buying);
        if (buying) {
            int buy = dfs(dp, prices, index + 1, !buying) - prices[index];
            dp[{index, buying}] = max(buy, cooldown);
        } else {
            int sell = dfs(dp, prices, index + 2, !buying) + prices[index];
            dp[{index, buying}] = max(sell, cooldown);
        }

        return dp[{index,buying}];
    }
};
