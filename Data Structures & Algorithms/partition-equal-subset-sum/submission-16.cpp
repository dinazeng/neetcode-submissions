class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }

        sum /= 2;

        return dfs(0, nums, sum, size);
    }

    bool dfs(int i, vector<int> &nums, int target, int &size) {
        if (target == 0) {
            return true;
        }

        if (i == size) {
            return false;
        }

        if (nums[i] <= target) {
            return dfs(i + 1, nums, target - nums[i], size) || dfs(i + 1, nums, target, size);
        }

        return dfs(i + 1, nums, target, size);
    }
};
