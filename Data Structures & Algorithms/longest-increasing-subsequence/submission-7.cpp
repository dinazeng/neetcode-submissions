class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        int max_element = 1;        
        vector<int> sol (size, 1);

        for (int i = size - 2; i >= 0; i--) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] < nums[j]) {
                    sol[i] = max(sol[j] + 1, sol[i]);
                }
            }

            max_element = max(max_element, sol[i]);
        }

        return max_element;
    }
};
