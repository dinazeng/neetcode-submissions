class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        if (length == 0) {
            return "";
        }

        if (length == 1) {
            return s;
        }

        int start = 0;
        int max_length = 0;

        for (int i = 0; i < length; i++) {
            expand(start, max_length, s, length, i - 1, i + 1);
            expand(start, max_length, s, length, i, i + 1);
        }

        return s.substr(start, max_length);
    }

    void expand (int &start, int &max_length, string &s, int &length, int l, int r) {
        while (r < length && l >= 0 && s[l] == s[r]) {
            l--;
            r++;
        }

        int curr_length = r - l - 1;
        if (curr_length > max_length) {
            start = l + 1;
            max_length = curr_length;
        }
    }
};
