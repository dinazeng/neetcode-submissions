class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map <int, int> freq_nums;

        for (int n : nums) {
            freq_nums[n]++;

            if (freq_nums[n] >= 2) {
                return true;
            }
        }

        return false;
    }
};