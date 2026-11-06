class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();

        if (len <= 1) {
            return s;
        }

        int start = 0;
        int max_len = 1;

        for (int i = 1; i < len; i++) {
            expand(s, i - 1, i + 1, len, max_len, start);
            expand(s, i - 1, i, len, max_len, start);
        }

        return s.substr(start, max_len);
    }

    void expand(string &s, int l, int r, int &len, int &max_len, int &start) {
        while (l >= 0 && r < len && s[l] == s[r]) {
            l--;
            r++;
        }

        int curr_len = r - l - 1;
        if (curr_len > max_len) {
            max_len = curr_len;
            start = l + 1;
        }
    }
};
