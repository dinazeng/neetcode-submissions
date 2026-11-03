class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> combos;
        vector<int> sub;

        makeCombos(nums, combos, sub, 0);

        return combos;
    }

    void makeCombos(vector<int> &nums, vector<vector<int>> &combos, vector<int> &sub, int i) {
        if (i == nums.size()) {
            combos.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        makeCombos(nums, combos, sub, i + 1);

        sub.pop_back();

        int size = nums.size();
        i++;
        while (i < size && nums[i] == nums[i - 1]) {
            i++;
        }

        makeCombos(nums, combos, sub, i);
    }
};
