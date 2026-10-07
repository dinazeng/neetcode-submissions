class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> solutions;
        vector<int> subset;

        dfs(solutions, subset, 0, target, candidates);

        return solutions;
    }

    void dfs(vector<vector<int>> &solutions, vector<int> &subset, int i, int target, vector<int> &candidates) {
        if (target == 0) {
            solutions.push_back(subset);
            return;
        }

        int candidates_size = candidates.size();

        if (target < 0 || i >= candidates_size || candidates[i] > target) {
            return;
        }

        subset.push_back(candidates[i]);
        dfs(solutions, subset, i + 1, target - candidates[i], candidates);

        while (i < candidates_size - 1 && candidates[i] == candidates[i + 1]) {
            i++;
        }
        
        subset.pop_back();
        dfs(solutions, subset, i + 1, target, candidates);
    }
};
