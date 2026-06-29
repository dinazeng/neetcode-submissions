class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int size = s.length();
        unordered_map <char, int> seen;
        int left = 0;

        for (int right = 0; right < size; right++) {
            char c = s[right];
            if (seen.contains(c) && seen[c] >= left) {
                left = seen[c] + 1;
            }
            maxLength = max (maxLength, right - left + 1);
            seen[c] = right;
        }
        
        return maxLength;
    }
};
