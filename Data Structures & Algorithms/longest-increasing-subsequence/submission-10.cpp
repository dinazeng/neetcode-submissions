class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }

        vector<int> dp(size, 1);
        int max_size = 1;

        for (int i = size - 2; i >= 0; i--) {
            int n = nums[i];
            for (int j = i + 1; j < size; j++) {
                if (nums[j] > n) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            max_size = max(dp[i], max_size);
        }

        return max_size;
    }
};
