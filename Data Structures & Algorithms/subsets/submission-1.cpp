class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return {};
        }

        vector<int> sub;
        vector<vector<int>> subset;
        makeSubs(subset, sub, 0, nums);

        return subset;
    }

    void makeSubs(vector<vector<int>> &subset, vector<int> &sub, int i, vector<int>& nums){
        if (i == nums.size()) {
            subset.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        makeSubs(subset, sub, i + 1, nums);
        sub.pop_back();
        makeSubs(subset, sub, i + 1, nums);
    }
};
