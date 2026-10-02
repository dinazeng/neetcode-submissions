class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> subset;

       sort(nums.begin(), nums.end());

        dfs(nums, 0, results, subset);

        return results;
    }

    void dfs(const vector<int> &nums, int i, vector<vector<int>>& results, vector<int>& subset) {
        if (i >= nums.size()) {
            results.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1, results, subset);
        subset.pop_back();

        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
            i++;
        }

        dfs(nums, i + 1, results, subset);
    }
};
