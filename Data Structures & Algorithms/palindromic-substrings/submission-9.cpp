class Solution {
public:
    int countSubstrings(string s) {
        int size = s.length();
        if (size <= 1) {
            return size;
        }

        int count = 1;
        for (int i = 1; i < size; i++) {
            expand(s, i, i, size, count);
            expand(s, i - 1, i, size, count);
        }

        return count;
    }

    void expand (string &s, int l, int r, int &size, int &count) {
        while (l >= 0 && r < size && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
    }
};
