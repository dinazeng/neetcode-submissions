class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int local_max = 1;
        int local_min = 1;

        for (int n : nums) {
            int temp = n * local_max;

            local_max = max(max(n, local_min*n), temp);
            local_min = min(min(n, temp), local_min * n);

            result = max(result, local_max);
        }

        return result;
    }
};
