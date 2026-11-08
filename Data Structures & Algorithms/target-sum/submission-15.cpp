class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return 0;

        vector<unordered_map<int, int>> dp (size + 1);
        dp[0][0] = 1;

        for (int i = 1; i <= size; i++) {
            for (auto &p : dp[i - 1]) {
                dp[i][p.first + nums[i - 1]] += p.second;
                dp[i][p.first - nums[i - 1]] += p.second;
            }
        }

        return dp[size][target];
    }
};
