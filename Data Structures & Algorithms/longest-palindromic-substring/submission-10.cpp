class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.length();

        if (size <= 1) {
            return s;
        }

        int start = 0;
        int max_length = 1;

        for (int i = 0; i < size; i++) {
            expand(i - 1, i + 1, s, size, max_length, start);
            expand(i, i + 1, s, size, max_length, start);
        }
        

        return s.substr(start, max_length);
    }

    void expand (int left, int right, string &s, int &size, int &max_length, int &start) {
        while (left >= 0 && left < size && right >= 0 && right < size && s[left] == s[right]) {
            left--;
            right++;
        }

        int curr_length = right - left - 1;
        if (curr_length > max_length) {
            max_length = curr_length;
            start = left + 1;
        }
    }
};
