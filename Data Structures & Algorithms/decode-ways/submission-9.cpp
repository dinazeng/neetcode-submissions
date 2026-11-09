class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len + 1);
        dp[len] = 1;

        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i < len - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};
