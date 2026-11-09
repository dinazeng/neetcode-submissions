class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }

        vector<int> dp (size, 1);
        int max_len = 1;

        for (int i = size - 2; i >= 0; i--) {
            int n = nums[i];

            for (int j = i + 1; j < size; j++) {
                if (nums[j] > n && dp[j] >= dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            max_len = max(dp[i], max_len);
        }

        return max_len;
    }
};
