class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size <= 1) {
            return size;
        }

        unordered_map<char, int> seen;
        int max_len = 0;
        int start = 0;

        for (int i = 0; i < size; i++) {
            char c = s[i];
            if (seen.contains(c) && seen[c] >= start) {
                start = seen[c] + 1;
            }

            seen[c] = i;
            max_len = max(max_len, i - start + 1);
        }
        
        return max_len;
    }   
};
