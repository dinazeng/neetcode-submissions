class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int length = s.length();
        
        unordered_map<char, int> last_seen;

        int left = 0; 
        for (int right = 0; right < length; right++) {
            char c = s[right];
            if (last_seen.contains(c)) {
                left = max(left, last_seen[c] + 1);
            }

            max_length = max(max_length, right - left + 1);
            last_seen[c] = right;
           
        }

        return max_length;
    }
};
