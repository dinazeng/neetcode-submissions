class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int types = coins.size();
        vector<vector<int>> combos (amount + 1, vector<int> (types + 1));

        for (int j = 0; j <= types; j++) combos[0][j] = 1;

        for (int i = 1; i <= amount; i++) {
            for (int j = 1; j <= types; j++) {
                combos[i][j] = combos[i][j - 1];
                if (coins[j - 1] <= i) {
                    combos[i][j] += combos[i - coins[j - 1]][j];
                }
            }
        }

        return combos[amount][types];
    }
};
