class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size() + 1);
        dp[0] = 0;

        for(int i = 0; i < nums.size(); i++) {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }

        return dp[nums.size()];
    }
};
