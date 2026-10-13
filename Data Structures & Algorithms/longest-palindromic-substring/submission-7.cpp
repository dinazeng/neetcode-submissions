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
            expand(i, i, s, length, start, max_length);
            expand(i, i + 1, s, length, start, max_length);
        }

        return s.substr(start, max_length);
    }

    void expand(int l, int r, string &s, int &length, int &start, int &max_length) {
        while (l >= 0 && r < length && s[l] == s[r]) {
            l--;
            r++;
        }

        int size = r - l - 1;
        if (size > max_length) {
            max_length = size;
            start = l + 1;
        }
    }
};