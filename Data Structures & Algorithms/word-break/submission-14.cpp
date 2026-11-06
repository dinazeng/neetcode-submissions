class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;

        for (int i = 0; i < len; i++) {
            if (!dp[i]) continue;
            for (const string &w : wordDict) {
                if (i + w.length() <= len && s.substr(i, w.length()) == w) {
                    dp[i + w.length()] = true;
                }
            }

        }

        return dp[len];
    }
};
