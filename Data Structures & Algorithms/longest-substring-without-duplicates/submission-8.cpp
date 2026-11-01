class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size <= 1) {
            return size;
        }

        map<char, int> last;
        int curr_length = 0;
        int max_length = 0;
        int left = 0;

        for (int right = 0; right < size; right++) {
            char process = s[right];
            if (last.contains(process) && last[process] >= left) {
                left = last[process] + 1; 
                curr_length = right - left + 1;
            } else {
                curr_length++;
            }

            last[process] = right;
            max_length = max(max_length, curr_length);
        }
        
        return max_length;
    }
};
