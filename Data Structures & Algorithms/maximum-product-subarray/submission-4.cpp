class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int max_product = 1;
        int min_product = 1;
        int res = nums[0];

        for (int num : nums) {
            int temp_max = num * max_product;

            max_product = max(max(num * max_product, num * min_product), num);
            min_product = min(min(temp_max, num * min_product), num);

            res = max(res, max_product);
        }

        return res;
    }
};
