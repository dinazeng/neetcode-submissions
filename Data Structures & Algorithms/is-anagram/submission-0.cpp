class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        map <char, int> freq_s;
        map <char, int> freq_t;

        for (char c : s) {
            freq_s[c]++;
        }

        for (char c: t) {
            freq_t[c]++;
        }

        if (freq_s != freq_t) {
            return false;
        }

        return true;
    }
};
