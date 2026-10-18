class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int total = size * (size + 1) / 2;

        for (int n : nums) {
            total -= n;
        }

        return total;
    }
};
