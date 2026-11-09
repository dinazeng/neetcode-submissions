class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_product = 1;
        int max_product = 1;
        int max_now = nums[0];

        for (const auto& n : nums) {
            int temp = n * min_product;

            min_product = min(min(temp, n * max_product), n);
            max_product = max(max(temp, n * max_product), n);

            max_now = max(max_now, max_product);
        }

        return max_now;
    }
};
