class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        
        if (size == 0) {
            return "";
        }

        int end = 1;
        int start = 0;

        for (int i = 0; i < size; i++) {
            dfs(s, i, i + 1, start, end);
            dfs(s, i, i + 2, start, end);
        }

        return s.substr(start, end);
    }

    void dfs (string &s, int l, int r, int &start, int &end) {
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        int size = r - l - 1;
        if (size > end) {
            end = size;
            start = l + 1;
        }
    }
};