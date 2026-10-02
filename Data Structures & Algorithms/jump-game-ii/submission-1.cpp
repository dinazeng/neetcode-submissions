class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();

        if (size <= 1) {
            return 0;
        }

        int min_jumps = 0;

        vector<int> jumps(size, INT_MAX - 1);
        jumps[0] = 0;
        for (int i = 0; i < size; i++) {
            int jump = nums[i];
            if (i + jump >= size - 1) {
                return jumps[i] + 1;
            }

            for (int j = i; j <= i + jump; j++) {
               jumps[j] = min(jumps[j], jumps[i] + 1);
            }

        }

        return jumps[size - 1];
    }
};
