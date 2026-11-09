class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return true;
        if (size == 1) return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        sum /= 2;
        
        vector<vector<int>> dp(sum + 1, vector<int>(size + 1));

        for (int i = 0; i <= size; i++) {
            dp[0][i] = true;
        }

        for (int j = 1; j <= sum; j++) {
            for (int k = 1; k <= size; k++) {
                dp[j][k] = dp[j][k - 1];

                if (nums[k - 1] <= j) {
                    dp[j][k] = dp[j - nums[k - 1]][k - 1] || dp[j][k];
                }
            }
        }

        return dp[sum][size];
    }
};
