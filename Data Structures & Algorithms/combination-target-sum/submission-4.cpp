class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> combos;
        vector<int> tryCom;
        makeCombos(combos, tryCom, 0, 0, nums, target);

        return combos;
    }

    void makeCombos(vector<vector<int>> &combos, vector<int>& tryCom, int sum, int i, vector<int>& nums, int &target) {
        if (sum == target) {
            combos.push_back(tryCom);
            return;
        }

        if (sum > target) {
            return;
        }

        if (i == nums.size()) {
            return;
        }

        tryCom.push_back(nums[i]);
        makeCombos(combos, tryCom, sum + nums[i], i, nums, target);
        tryCom.pop_back();
        makeCombos(combos, tryCom, sum, i + 1, nums, target);
    }
};
