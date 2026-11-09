class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        if (len <= 1) {
            return len;
        }

        int total = 1;

        for (int i = 1; i < len; i++) {
            total += 1 + expand(s, i - 1, i + 1, len);
            total += expand(s, i - 1, i, len);
        }

        return total;
    }

    int expand(string& s, int l, int r, int& len) {
        int count = 0;
        while (l >= 0 && r < len && s[l] == s[r]) {
            l--;
            r++;
            count++;
        }

       return count;
    }
};
