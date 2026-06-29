class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<bool> jumps (size, false);
        jumps[0] = true;

        for (int i = 0; i < size; i++) {
            if (jumps[i]) {
                int jump = i + nums[i] + 1 >= size ? size : i + nums[i] + 1;

                for (int j = 0; j < jump; j++) {
                    jumps[j] = true;
                }
            }
        }


        return jumps[size - 1];
    }
};
