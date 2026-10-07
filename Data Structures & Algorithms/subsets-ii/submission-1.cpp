class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> solutions;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(solutions, nums, 0, subset);

        return solutions;
    }

    void dfs(vector<vector<int>> &solutions, vector<int> &nums, int i, vector<int> &subset) {
        int size = nums.size();
        if (i == size) {
            solutions.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(solutions, nums, i + 1, subset);
        subset.pop_back();
        while (i < size - 1 && nums[i] == nums[i + 1]) {
            i++;
        }

        dfs(solutions, nums, i + 1, subset);
    }
};
