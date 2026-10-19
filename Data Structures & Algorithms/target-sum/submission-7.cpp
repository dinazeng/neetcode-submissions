class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        vector<unordered_map<int, int>> ways (size + 1);
        ways[0][0] = 1;

        for (int i = 0; i < size; i++) {
            for (auto &p : ways[i]) {
                ways[i + 1][p.first - nums[i]] += p.second;
                ways[i + 1][p.first + nums[i]] += p.second;
            }
        }

        return ways[size][target];
    }
};
