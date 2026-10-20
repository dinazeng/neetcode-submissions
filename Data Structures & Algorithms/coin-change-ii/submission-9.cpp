class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int coin_types = coins.size();
        vector<vector<int>> change_combos (amount + 1, vector<int> (coin_types + 1));
        
        for (int i = 0; i <= coin_types; i++) {
            change_combos[0][i] = 1;
        }

        for (int i = 0; i <= amount; i++) {
            for (int j = 1; j <= coin_types; j++) {
                change_combos [i][j] = change_combos[i][j - 1];
                if (coins[j - 1] <= i) {
                    change_combos[i][j] += change_combos[i - coins[j - 1]][j];
                }
            }
        }

        return change_combos[amount][coin_types];
    }
};
