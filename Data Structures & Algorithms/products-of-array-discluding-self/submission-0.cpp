class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> products(size, 1);
        
        int curr = 1;

        for (int i = 1; i < size; i++) {
            curr *= nums[i - 1];

            products[i] = curr;
        }

        curr = 1; 

        for (int i = size - 2; i >= 0; i--) {
            curr *= nums[i + 1];

            products[i] *= curr;
        }

        return products;
    }
};
