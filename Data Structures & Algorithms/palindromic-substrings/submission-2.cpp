class Solution {
public:
    int countSubstrings(string s) {
        int size = s.length();
        if (size <= 1) {
            return size;
        }

        int count = 1;
        for (int i = 1; i < size; i++) {
            count += 1 + dfs(i - 1, i + 1, s, size);
            count += dfs(i - 1, i, s, size);
        }

        return count;
    }

    int dfs(int l, int r, string &s, int &size) {
        if (l < 0 || r >= size) {
            return 0;
        }

        if (s[l] != s[r]) {
            return 0;
        }

        return 1 + dfs(l - 1, r + 1, s, size);
    }
};
