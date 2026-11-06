class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return true;
        }

        if (size == 1) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;

        sum /= 2;

        vector<vector<bool>> dp(sum + 1, vector<bool> (size + 1, false));
        
        for (int i = 0; i <= size; i++) {
            dp[0][i] = true;
        }

        for (int i = 1; i <= sum; i++) {
            for (int j = 1; j <= size; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i >= nums[j - 1]) {
                    dp[i][j] = dp[i - nums[j - 1]][j - 1] || dp[i][j];
                }
            }
        }

        return dp[sum][size];
    }
};
