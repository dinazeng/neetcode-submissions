class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int size = s.size();

        unordered_map<char, int> last_seen;
        int start = 0;
        int curr_length = 0;
        for (int i = 0; i < size; i++) {
            if (last_seen.contains(s[i]) && last_seen[s[i]] >= start) {
                start = last_seen[s[i]] + 1;
                curr_length = i - start + 1;
            } else {
                curr_length++;
            }

            last_seen[s[i]] = i;
            max_length = max(max_length, curr_length);
        }


        return max_length;
    }
};
