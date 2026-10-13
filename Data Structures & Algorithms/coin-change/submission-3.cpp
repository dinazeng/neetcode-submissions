class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        int types = coins.size();
        vector<int> sol (amount + 1, -1);
        sol[0] = 0;

        for (int i = 0; i < amount; i++) {
            if (sol[i] == -1) continue;

            for (int j = 0; j < types; j++) {
                long value = coins[j];
                if (i + value <= amount) {
                    if (sol[i + value] == -1) {
                        sol[i + value] = sol[i] + 1;
                    } else {
                        sol[i + value] = min(sol[i + value], sol[i] + 1);
                    }
                }
            }
        }


        return sol[amount];
    }
};
