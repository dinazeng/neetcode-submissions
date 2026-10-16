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

        if (size == 2) {
            return max(nums[0], nums[1]);
        }
        
        int score_one = robbery(vector<int> (nums.begin() + 1, nums.end())); 
        int score_two = robbery(vector<int> (nums.begin(), nums.end() - 1)); 

        return max(score_one, score_two);
    }

    int robbery (vector<int> nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0]; 
        }

        vector<int> score(size + 1);

        score[0] = 0;
        score[1] = nums[0];

        for (int i = 1; i < size; i++) {
            score[i + 1] = max(score[i - 1] + nums[i], score[i]);
        }

        return score[size];
    }
};
