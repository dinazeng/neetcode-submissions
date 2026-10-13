class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }

        sum /= 2;

        vector<vector<bool>> sol (sum + 1, vector<bool> (size + 1, false));
        
        for (int i = 0; i <= size; i++) {
            sol[0][i] = true;
        }

        for (int i = 1; i <= sum; i++) {
            for (int j = 1; j <= size; j++) {
                if (i >= nums[j - 1]) {
                    sol[i][j] = sol[i - nums[j - 1]][j - 1] || sol[i][j - 1];
                } else {
                    sol[i][j] = sol[i][j - 1];
                }
            }
        }


        return sol[sum][size];

    }
};
