class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<pair<int, bool>, int> status;
        return dfs(status, prices, 0, true);
    }

    int dfs(map<pair<int, bool>, int>& status, vector<int>& prices, int i, bool buying) {
        if (i >= prices.size()) {
            return 0;
        }

        if (status.contains({i, buying})) {
            return status[{i, buying}];
        }

        int cooldown = dfs(status, prices, i + 1, buying);

        if (buying) {
            int buy = dfs(status, prices, i + 1, !buying) - prices[i];

            status[{i, buying}] = max(buy, cooldown);
        } else {
            int sell = dfs(status, prices, i + 2, !buying) + prices[i];
            
            status[{i, buying}] = max(sell, cooldown);
        }

        return status[{i, buying}];
    }
};
