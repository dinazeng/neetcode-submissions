class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumTotal = accumulate(nums.begin(), nums.end(), 0);

        if (sumTotal % 2 != 0) {
            return false;
        }

        sumTotal /= 2;

        int size = nums.size();

        vector<bool> dp (sumTotal + 1, false);

        dp[0] = true;

        for (int i = 0; i < size; i++) {
            for (int j = sumTotal; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[sumTotal];
    }
};
