class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size <= 1) {
            return size;
        }

        map<char, int> last_seen;
        int max_length = 0;

        int l = 0;
        int curr_length = 0;

        for (int r = 0; r < size; r++) {
            char check = s[r];
            if (last_seen.contains(check) && last_seen[check] >= l) {
                l = last_seen[check] + 1;
                curr_length = r - l + 1;
            } else {
                curr_length++;
            }

            last_seen[check] = r;
            max_length = max(max_length, curr_length);
        }

        return max_length;
    }
};
