class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums, 0, target, subset, result, 0);

        return result;
    }

    void dfs(const vector<int>&nums, int i, int target, vector<int>&subset, vector<vector<int>>&result, int curr) {
        if (i >= nums.size() || curr > target) {
            return;
        }

        if (curr == target) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        curr += nums[i];
        dfs(nums, i, target, subset, result, curr);
        subset.pop_back();
        curr -= nums[i];
        dfs(nums, i + 1, target, subset, result, curr);
    }
};
