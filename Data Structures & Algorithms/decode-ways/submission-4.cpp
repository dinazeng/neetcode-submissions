class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        vector<int> dp(size + 1, 1);
        dp[size] = 1;

        for (int i = size - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < size && ((s[i] == '2' && s[i + 1] <= '6') || s[i] == '1')) {
                    dp[i] += dp[i + 2];
                }
            }
        }


        return dp[0];
    }
};
