class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int types = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> combination(amount + 1, vector<int> (types + 1, 0));

        for (int i = 0; i <= types; i++) {
            combination[0][i] = 1;
        }

        for (int j = types - 1; j >= 0; j--) {
            for (int i = 0; i <= amount; i++) {
                if (i >= coins[j]) {
                    combination[i][j] = combination[i][j + 1] + combination[i - coins[j]][j];
                }
            }
        }

        return combination[amount][0];
    }
};
