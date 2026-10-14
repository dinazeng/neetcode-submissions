class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                swap(nums[i], nums[k++]);
            }
        }

        return k;
    }
};