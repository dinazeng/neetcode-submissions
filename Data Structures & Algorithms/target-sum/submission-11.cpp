class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        vector<unordered_map<int, int>> status (size + 1);
        status[0][0] = 1;

        for (int i = 0; i < size; i++) {
            for (auto &p : status[i]) {
                status[i + 1][p.first - nums[i]] += p.second;
                status[i + 1][p.first + nums[i]] += p.second;
            }
        }

        return status[size][target];
    }
};
