class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total) return 0;

        vector<vector<int>> v(2 * total + 1, vector<int>(size + 1, 0));
        v[total][0] = 1;                       // sum 0, zero numbers used

        for (int j = 1; j <= size; j++) {      // items on the outside
            for (int i = 0; i <= 2 * total; i++) {
                if (v[i][j - 1] == 0) continue; // skip unreachable source
                v[i + nums[j - 1]][j] += v[i][j - 1];
                v[i - nums[j - 1]][j] += v[i][j - 1];
            }
        }

        return v[target + total][size];
    }
};