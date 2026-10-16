class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        int score = nums[0];
        int min_score = 1;
        int max_score = 1;

        for (int i = 0; i < size; i++) {
            int n = nums[i];
            int temp = max_score * n;

            max_score = max(max(temp, min_score * n), n);
            min_score = min(min(temp, min_score * n), n);

            score = max(score, max_score);
        }

        return score;
    }
};
