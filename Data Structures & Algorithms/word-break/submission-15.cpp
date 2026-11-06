class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;

        for (int i = 0; i < len; i++) {
            if (!dp[i]) continue;
            for (const string &w : wordDict) {
                int w_len = w.length();
                if (i + w_len <= len && s.substr(i, w_len) == w) {
                    dp[i + w_len] = true;
                }
            }
        }

        return dp[len];
    }
};
