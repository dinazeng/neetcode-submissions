class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);

        return max(helper_rob(vector<int>(nums.begin() + 1, nums.end())), helper_rob(vector<int>(nums.begin(), nums.end() - 1)));
    }

    int helper_rob(vector<int> nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        vector<int> dp(size);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[size - 1];
    }
};
