class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumTotal = accumulate(nums.begin(), nums.end(), 0);

        if (sumTotal % 2 != 0) {
            return false;
        }

        sumTotal /= 2;

        int size = nums.size();

        vector<vector<bool>> dp (sumTotal + 1, vector<bool> (size + 1, false));

         for (int i = 0; i <= size; i++) {
            dp[0][i] = true;
        }

        for (int i = 1; i <= sumTotal; i++) {
            for (int j = 1; j <= size; j++) {
                if (nums[j - 1] <= i) {
                    dp[i][j] = dp[i - nums[j - 1]][j - 1] || dp [i][j - 1];
                } else {
                    dp[i][j] = dp [i][j - 1];
                }
               
            }
        }

        return dp[sumTotal][size];
    }
};
