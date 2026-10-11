class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0) {
            return 0;
        }

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
