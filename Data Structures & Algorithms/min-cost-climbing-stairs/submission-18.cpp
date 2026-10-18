class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (size == 0) {
            return 0;
        }

        if (size == 1) {
            return cost[0];
        }

        vector<int> climb (size + 1);
        for (int i = 2; i <= size; i++) {
            climb[i] = min(climb[i - 1] + cost[i - 1], climb[i - 2] + cost[i - 2]);
        } 

        return climb[size];
    }
};
