class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) {
            return {};
        }

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combos;
        vector<int> sub;

        makeCombos(candidates, target, combos, sub, 0, 0);

        return combos;
    }

    void makeCombos(vector<int> &candidates, int &target, vector<vector<int>> &combos, vector<int> &sub, int sum, int i) {
        if (target == sum) {
            combos.push_back(sub);
            return;
        }

        if (i == candidates.size()) {
            return;
        }

        if (sum > target) {
            return;
        }

        sub.push_back(candidates[i]);
        makeCombos(candidates, target, combos, sub, sum + candidates[i], i + 1);

        sub.pop_back();

        int size = candidates.size();
        i++;
        while (i < size && candidates[i] == candidates[i - 1]) {
            i++;
        }

        makeCombos(candidates, target, combos, sub, sum, i);
    }
};
