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

        if (size == 1) {
            return nums[0];
        }

        int score_one = 0;
        int score_two = 0;

        for (int i = 0; i < size; i++) {
            int temp = max(nums[i] + score_two, score_one);

            score_two = score_one;
            score_one = temp;
        }

        return max(score_one, score_two);
    }
};
