class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        map<pair<int, bool>, int> profits;
        
        return dfs(profits, prices, size, 0, true);
    }

    int dfs (map<pair<int, bool>, int>& profits, vector<int>& prices, int& size, int index, bool buying) {
        if (index >= size) {
            return 0;
        }

        if (profits.contains({index, buying})) {
            return profits[{index, buying}];
        }

        int cooldown = dfs(profits, prices, size, index + 1, buying);

        if (buying) {
            int bought = dfs(profits, prices, size, index + 1, !buying) - prices[index];
            
            profits[{index, buying}] = max(bought, cooldown);
        } else {
            int sold = dfs(profits, prices, size, index + 2, !buying) + prices[index];
            
            profits[{index, buying}] = max(sold, cooldown);
        }

        return profits[{index, buying}];
    }
};
