class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") {
            return "";
        }

        int s_len = s.length();

        unordered_map<char, int> freq_s;
        unordered_map<char, int> freq_t;

        for (const auto& c : t) {
            freq_t[c]++;
        }

        int l = 0;
        int max_length = INT_MAX;
        int start = l;

        int got = 0;
        int want = freq_t.size();

        for (int r = 0; r < s_len; r++) {
            char c = s[r];

            freq_s[c]++;
            if (freq_t.contains(c) && freq_s[c] == freq_t[c]) {
                got++;
            }

            while (got == want) {
                if (r - l + 1 < max_length) {
                    max_length = r - l + 1;
                    start = l;
                }

                char rem = s[l];
                freq_s[rem]--;
                if (freq_t.contains(rem) && freq_s[rem] < freq_t[rem]) {
                    got--;
                }

                l++;
            }
        }

        return max_length != INT_MAX ? s.substr(start, max_length) : "";
    }
};
