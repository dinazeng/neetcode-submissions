class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        if (size == 0) {
            return 0;
        }

        int count = 1;
        for (int i = 1; i < size; i++) {
            count += 1 + dfs (i - 1, i + 1, s, size);
            count += dfs(i - 1, i, s, size);
        }

        return count;
    }

    int dfs(int l, int r, string &s, int &size) {
        int count = 0;
        while (l >= 0 && r < size && s[l] == s[r] ) {
            count++;
            l--;
            r++;
        }

        return count;
    }   
};
