class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> tracker (nums.begin(), nums.end());
        int longest = 0;

        for (int n : nums) {
            if (tracker.find(n - 1) == tracker.end()) {
                int length = 1;
                while (tracker.find(n + length) != tracker.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
