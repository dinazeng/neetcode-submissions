class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int, int> comp;

        for (int i = 0; i < size; i++) {
            int complement = target - nums[i];
            comp[complement] = i;
        }

        for (int i = 0; i < size; i++) {
            int n = nums[i];
            if (comp.contains(n) && comp[n] != i) {
                return {i, comp[n]};
            }
        }

        return {};
    }
};
