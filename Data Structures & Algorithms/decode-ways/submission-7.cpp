class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        vector<int> dp(size + 1, 0);
        dp[size] = 1;

        for (int i = size - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i < size - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};
