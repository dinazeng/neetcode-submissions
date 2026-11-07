class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;


        for (const int &p : prices) {
            max_profit = max(p - min_price, max_profit);
            min_price = min(p, min_price);
        }

        return max_profit;
    }
};
