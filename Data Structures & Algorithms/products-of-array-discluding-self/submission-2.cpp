class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        int size = nums.size();

        vector<int> sol(size);
        sol[0] = 1;

        for (int i = 1; i < size; i++) {
            prefix *= nums[i - 1];
            sol[i] = prefix;
        }

        prefix = 1;

        for (int i = size - 2; i >= 0; i--) {
            prefix *= nums[i + 1];
            sol[i] *= prefix;
        }
          
        return sol;
    }
};
