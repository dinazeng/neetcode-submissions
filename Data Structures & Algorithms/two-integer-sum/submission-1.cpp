class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> complement_index;

        for (int i = 0; i < nums.size(); i++) {
            complement_index[target - nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (complement_index.contains(nums[i]) && i != complement_index[nums[i]]) {
                return {i, complement_index[nums[i]]};
            }
        }

        return {};
    }
};
