class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        int max_length = 1;
        vector<int> sol (size, 1);
        
        for (int i = size - 1; i >= 0; i--) {
            int curr_length = 1;

            for (int j = i + 1; j < size; j++) {
                if (nums[i] < nums[j]) {
                    curr_length = max(curr_length, sol[j] + 1);
                }
            }

            max_length = max(curr_length, max_length);
            sol[i] = curr_length;
        }

        
        return max_length;
    }
};
