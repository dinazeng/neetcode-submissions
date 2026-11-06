class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0];
        int curr_max = 1;
        int curr_min = 1;

        for (int i : nums) {
            int temp = curr_min;

            curr_min = min(min(curr_min * i, curr_max * i), i);
            curr_max = max(max(temp * i, curr_max * i), i);

            max_product = max(max_product, curr_max);
        }

        return max_product;
    }
};
