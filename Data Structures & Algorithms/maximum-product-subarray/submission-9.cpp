class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int max_element = 1;
        int min_element = 1;

        for (int n : nums) {
            int temp = max_element * n;

            max_element = max(max(temp, min_element * n), n);
            min_element = min(min(min_element * n, temp), n);

            result = max(max_element, result);
        }

        return result;
    }
};
