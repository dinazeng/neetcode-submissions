class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        set<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i++) {
            int target = -1 * nums[i];
            for (int j = i + 1; j < size - 1; j++) {
                for (int k = size - 1; k > j; k--) {
                    if (nums[j] + nums[k] == target) {
                        results.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return vector<vector<int>> (results.begin(), results.end());
    }
};
