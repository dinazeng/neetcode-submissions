class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") {
            return "";
        }

        unordered_map<char, int> s_win;
        unordered_map<char, int> t_win;
        
        for (char c : t) {
            t_win[c]++;
        }

        int have = 0;
        int need = t_win.size();
        int len = s.length();

        int l = 0;
        int res_start = 0;
        int res_len = INT_MAX;

        for (int r = 0; r < len; r++) {
            char c = s[r];
            s_win[c]++;

            if (t_win.contains(c) && s_win[c] == t_win[c]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < res_len) {
                    res_start = l;
                    res_len = r - l + 1;
                }

                s_win[s[l]]--;
                if (t_win.contains(s[l]) && s_win[s[l]] < t_win[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        
        return res_len == INT_MAX ? "" : s.substr(res_start, res_len);
    }
};
