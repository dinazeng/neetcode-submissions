class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0) {
            return 0;
        }

        if (size == 1) {
            return nums[0];
        }

        if (size == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> noFirst = vector<int>(nums.begin() + 1, nums.end());
        vector<int> noLast = vector<int>(nums.begin(), nums.end() - 1);

        return max(helper(noFirst), helper(noLast));
    }

    int helper(vector<int>& nums) {
        int size = nums.size();

        vector<int> money(size);

        money[0] = nums[0];
        money[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < size; i++) {
            money[i] = max(money[i - 1], nums[i] + money[i - 2]);
        }

        return money[size - 1];
    }
};
