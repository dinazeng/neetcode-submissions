class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> solution;
        vector<int> subset;

        dfs(solution, subset, nums, 0, target);

        return solution;
    }

    void dfs(vector<vector<int>> &solution, vector<int> &subset, vector<int> &nums, int i, int target) {
        if (target == 0) {
            solution.push_back(subset);
            return;
        }

        if (target < 0 || i == nums.size()) {
            return;
        }

        subset.push_back(nums[i]);
        dfs(solution, subset, nums, i, target - nums[i]);
        subset.pop_back();
        dfs(solution, subset, nums, i + 1, target);
    }
};
