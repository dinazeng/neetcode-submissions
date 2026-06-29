class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();

        if (size == 0) {
            return 0;
        }

        int minProd = 1;
        int maxProd = 1;
        int result = nums[0];

        for (int i = 0; i < size; i++) {
            int currMax = maxProd*nums[i];

            maxProd = max(max(nums[i] * maxProd, nums[i]* minProd), nums[i
            ]);
            minProd = min(min(currMax, nums[i]* minProd), nums[i]);

            result = max (result, maxProd);
        }
        
        return result;
    }
};
