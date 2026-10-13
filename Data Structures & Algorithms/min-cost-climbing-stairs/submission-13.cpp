class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int size = cost.size();
        vector<int> climbs(size + 1, 0);
        
        for (int i = 2; i <= size; i++) {
                climbs[i] = min(cost[i - 1] + climbs[i - 1], cost[i - 2] + climbs[i - 2]);
        }

         return climbs[size];
    }
};
