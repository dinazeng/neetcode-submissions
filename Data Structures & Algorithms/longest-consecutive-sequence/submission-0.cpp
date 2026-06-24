class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> tracker (nums.begin(), nums.end());
        int result = 0;

        for (int n : nums) {
            int streak = 0;
            int curr = n;
            while (tracker.contains(curr)) {
                streak++;
                curr++;
            }

            result = max(result, streak);
        }

        return result;
    }
};
