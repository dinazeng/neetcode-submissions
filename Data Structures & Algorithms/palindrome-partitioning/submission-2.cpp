class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> substrings;
        vector<string> curr;
        dfs(substrings, curr, 0, s);
        return substrings;
    }

    void dfs(vector<vector<string>> &substrings, vector<string> &curr, int start, string &s) {
        if (start == s.length()) {
            substrings.push_back(curr);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                dfs(substrings, curr, end + 1, s);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }

        return true;
    }
};
