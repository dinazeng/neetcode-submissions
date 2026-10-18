class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }
        
        int max_size = 1;
        vector<int> dp(size, 1);

        for (int i = size - 1; i >= 0; i--) {
            int curr = nums[i];
            for (int j = i + 1; j < size; j++) {
                if (nums[j] > curr) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            max_size = max(dp[i], max_size);
        }


        return max_size;
    }
};
