class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers;

        for (int n : nums) {
            numbers.insert(n);
        }

        int longest = 0;

        for (int n : nums) {
            if (numbers.contains(n - 1)) continue;
            int current = 1;
            int i = n;
            while (numbers.contains(i + 1)) {
                i++;
                current++;
            }

            longest = max(current, longest);
        }

        return longest;
    }
};
