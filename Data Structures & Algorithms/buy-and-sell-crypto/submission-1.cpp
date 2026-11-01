class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0];
        int max_profit = 0;

        for (int i : prices) {
            max_profit = max(i - min_buy, max_profit);
            min_buy = min(min_buy, i);
        }

        return max_profit;
    }
};
