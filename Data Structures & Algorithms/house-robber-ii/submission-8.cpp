class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }


        vector<int> one = vector<int>(nums.begin(), nums.end() - 1);
        vector<int> two = vector<int>(nums.begin() + 1, nums.end());

        return max(rob_help(one), rob_help(two));
    }

    int rob_help(vector<int>& nums) {
        int size = nums.size();

        if (size == 0) {
            return 0;
        }

        if (size == 1) {
            return nums[0];
        }

        vector<int> score (size);

        score[0] = nums[0];
        score[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            score[i] = max(score[i - 1], score[i - 2] + nums[i]);
        }

        return max(score[size - 1], score[size - 2]);
    }
};
