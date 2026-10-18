class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> step (size + 1);

        for (int i = 2; i <= size; i++) {
            step[i] = min(cost[i - 2] + step[i - 2], cost[i - 1] + step [i - 1]);
        }

        return step[size];
    }
};
