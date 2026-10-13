class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int types = coins.size();
        vector<int> sol (amount + 1, amount + 1);
        sol[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < types; j++) {
                if (i >= coins[j]) {
                    sol[i] = min(sol[i], 1 + sol[i - coins[j]]);
                }
            }
        }


        return sol[amount] <= amount ? sol[amount] : -1;
    }
};
