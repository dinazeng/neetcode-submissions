class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> stairCost(size + 1);

        stairCost[0] = cost[0];
        stairCost[1] = cost[1];

        for (int i = 2; i < size; i++) {
            stairCost[i] = cost[i] + min(stairCost[i - 1], stairCost[i - 2]);
        }

        return min(stairCost[size - 1], stairCost[size - 2]);
    }
};
