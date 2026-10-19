class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<pair<int, int>, int> dp;
        return dfs(prices, dp, 0, true);
    }

    int dfs (vector<int> &prices, map<pair<int, int>, int> &dp, int i, bool buying) {
        if (i >= prices.size()) {
            return 0;
        }

        if (dp.contains({i, buying})) {
            return dp[{i, buying}];
        }

        int cooldown = dfs(prices, dp, i + 1, buying);
        if (buying) {
            int buy = dfs(prices, dp, i + 1, !buying) - prices[i];      
            dp[{i, buying}] = max(buy, cooldown);
        } else {
            int sell = dfs(prices, dp, i + 2, !buying) + prices[i];
            dp[{i, buying}] = max(sell, cooldown);
        }

        return dp[{i, buying}];
    }

   
};
