class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> freq_s;

        for (char c : s) {
            freq_s[c]++;
        }

        for (char c : t) {
            if (!freq_s.contains(c)) {
                return false;
            }

            freq_s[c]--;
            if (freq_s[c] == 0) {
                freq_s.erase(c);
            }
        }

        return freq_s.size() == 0;
    }
};
