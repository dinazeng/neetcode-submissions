class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();

        vector<bool> dp (size + 1, false);
        dp[size] = true;

        for (int i = size - 1; i >= 0; i--) {
            for (string &w : wordDict) {
                if ((i + w.size()) <= size && s.substr(i, w.size()) == w) {
                    dp[i] = dp[i + w.size()];
                }

                if (dp[i]) {
                    break;
                }
            }
        }

        return dp[0];
    }
};
