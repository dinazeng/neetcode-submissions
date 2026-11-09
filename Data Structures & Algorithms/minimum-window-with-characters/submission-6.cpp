class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") {
            return "";
        }

        int size = s.size();

        unordered_map<char, int> need;
        unordered_map<char, int> have;

        for (char c : t) {
            need[c]++;
        }

        int want = need.size();
        int got = 0;

        int l = 0;
        int result_length = INT_MAX;
        int res_start = 0;


        for (int r = 0; r < size; r++) {
            char c = s[r];
            have[c]++;

            if (have[c] == need[c]) {
                got++;
            }

            while (got == want) {
                if ((r - l + 1) < result_length) {
                    res_start = l;
                    result_length = r - l + 1;

                }

                have[s[l]]--;
                if (need.contains(s[l]) && have[s[l]] < need[s[l]]) {
                    got--;
                }

                l++;
            }
        }

        return result_length == INT_MAX ? "" : s.substr(res_start, result_length);
    }
};
