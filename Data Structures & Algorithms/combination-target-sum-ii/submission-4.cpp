class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, 0, results, subset, 0, target);

        return results;
    }

    void dfs(vector<int>&candidates, int i, vector<vector<int>>& results, vector<int>& subset, int curr, int target) {
        if (curr == target) {
            results.push_back(subset);
            return;
        }

        int size = candidates.size();
        
        if (i >= size || curr > target) {
            return;
        }

        subset.push_back(candidates[i]);
        curr += candidates[i];
        dfs(candidates, i + 1, results, subset, curr, target);
        subset.pop_back();
        curr -= candidates[i];
        while (i < size - 1 && candidates[i] == candidates[i + 1]) {
            i++;
        }
    
        dfs(candidates, i + 1, results, subset, curr, target);
    }
};